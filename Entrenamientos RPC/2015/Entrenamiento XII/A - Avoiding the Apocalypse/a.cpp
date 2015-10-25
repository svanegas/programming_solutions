#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 102005;
int t_limit;

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

int
conv(int node, int _time) {
  return node * (t_limit + 1) + _time;
}

int
main() {
  int z; cin >> z;
  while (z--) {
    int n, str, ppl;
    cin >> n >> str >> ppl >> t_limit;
    PushRelabel relabel = PushRelabel(n * (t_limit + 1) + 2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < t_limit; ++j) {
        relabel.AddEdge(conv(i, j), conv(i, j + 1), ppl);
      }
    }
    int source = conv(n, 0), dest = source + 1;
    int m; cin >> m;
    str--;
    relabel.AddEdge(source, conv(str, 0), ppl);
    for (int i = 0; i < m; ++i) {
      int fac; cin >> fac; fac--;
      for (int j = 0; j <= t_limit; ++j) {
        relabel.AddEdge(conv(fac, j), dest, ppl);
      }
    }
    int roads; cin >> roads;
    for (int i = 0; i < roads; ++i) {
      int a, b, p, steps;
      cin >> a >> b >> p >> steps;
      a--; b--;
      for (int j = 0; j <= t_limit - steps; ++j) {
        relabel.AddEdge(conv(a, j), conv(b, j + steps), p);
      }
    }
    cout << relabel.GetMaxFlow(source, dest) << endl;
  }
  return 0;
}
