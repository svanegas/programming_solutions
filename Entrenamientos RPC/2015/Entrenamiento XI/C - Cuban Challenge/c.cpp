// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 25;
const int MAXM = 1005;
const int MAXX = MAXN * MAXM;
char board[MAXN][MAXM];
bool visited[MAXN][MAXM];
pii color[MAXN][MAXM];
int L, R;
set <int> eleft[MAXX];
int dirI[] = { -1, 0,  0, 1 };
int dirJ[] = {  0, 1, -1, 0 };

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) : from(from), to(to), cap(cap), flow(flow),
  index(index) {}
};

struct PushRelabel {
  int N;
  vector <vector <Edge> > G;
  vector <LL> excess;
  vector <int> dist, active, count;
  queue <int> Q;
  PushRelabel(int N) : N(N),
  G(N),
  excess(N),
  dist(N),
  active(N),
  count(2 * N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) {
      active[v] = true;
      Q.push(v);
    }
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; ++v) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }
  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2 * N;
    for (int i = 0; i < G[v].size(); ++i)
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); ++i) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
        Gap(dist[v]);
      else
        Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N - 1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); ++i) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); ++i) totflow += G[s][i].flow;
    return totflow;
  }
};

int n, m;

void
bfs(int i, int j, PushRelabel &relabel) {
  visited[i][j] = true;
  color[i][j] = pii(1, L++);
  queue <pii> q;
  q.push(pii(i, j));
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    int i = cur.first, j = cur.second;
    int my_color = color[i][j].second;
    bool left = color[i][j].first;
    for (int k = 0; k < 4; ++k) {
      int nI = i + dirI[k], nJ = j + dirJ[k];
      if (nI >= 0 && nI < n && nJ >= 0 && nJ < m && board[nI][nJ] == '.') {
        if (visited[nI][nJ]) {
          int ind = color[nI][nJ].second;
          if (left) eleft[my_color].insert(ind);
          else eleft[ind].insert(my_color);
        }
        else {
          if (left) eleft[my_color].insert(R);
          else eleft[L].insert(my_color);
          visited[nI][nJ] = true;
          color[nI][nJ] = pii(1 - left, 1 - left ? L++ : R++);
          q.push(pii(nI, nJ));
        }
      }
    }
  }
}


int
main() {
  int z = 1;
  while (scanf("%d %d", &n, &m) && n) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        visited[i][j] = false;
        eleft[i * m + j].clear();
      }
    }
    int nodes = 0;
    for (int i = 0; i < n; ++i) {
      getchar();
      for (int j = 0; j < m; ++j) {
        board[i][j] = getchar();
        nodes += (board[i][j] == '.');
      }
    }
    int source = nodes, dest = nodes + 1;
    PushRelabel relabel = PushRelabel(nodes + 2);
    L = R = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && board[i][j] == '.') bfs(i, j, relabel);
      }
    }
    for (int i = 0; i < L; ++i) {
      relabel.AddEdge(source, i, 1);
      set <int> :: iterator j;
      for (j = eleft[i].begin(); j != eleft[i].end(); ++j) {
        int elem = *j;
        relabel.AddEdge(i, L + elem, 1);
      }
    }
    for (int j = 0; j < R; ++j) relabel.AddEdge(L + j, dest, 1);

    LL tiles = relabel.GetMaxFlow(source, dest);
    int ans = (L + R) - ((int) tiles) * 2;
    ans = (ans + 1) / 2;
    printf("Case #%d: %d\n", z++, ans);
  }
  return 0;
}
