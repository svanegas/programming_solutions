#include <bits/stdc++.h>

using namespace std;

struct edge {
  int to, cost, fuel;
  edge(int _to, int _cost, int _fuel) : to(_to), cost(_cost), fuel(_fuel) { }
  bool operator > (const edge &than) const {
    return cost > than.cost;
  }
};

typedef pair <int, int> path;
const int MAXN = 1005;
const int MAXC = 105;
int n, m, q, cap;
int price[MAXN], d[MAXN][MAXC];
vector <path> road[MAXN];
vector <edge> g[MAXN];

void
dijkstra(int s) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= cap; ++j) {
      d[i][j] = INT_MAX;
    }
    g[i].clear();
  }
  priority_queue <edge, vector <edge>, greater <edge> > q;
  d[s][0] = 0;
  q.push(edge(s, 0, 0));
  while (!q.empty()) {
    int cur = q.top().to;
    int dist = q.top().cost;
    int avail = q.top().fuel;
    q.pop();
    if (dist > d[cur][avail]) continue;
    for (int i = 0; i < road[cur].size(); ++i) {
      int next = road[cur][i].first;
      int length = road[cur][i].second;
      int burned = avail - length;
      if (burned >= 0 && d[cur][avail] < d[next][burned]) {
        // I can go to that city without buying fuel.
        d[next][burned] = d[cur][avail];
        q.push(edge(next, d[next][burned], burned));
      }
    }
    // Buy fuel if I have capacity
    if (avail + 1 <= cap && d[cur][avail] + price[cur] < d[cur][avail + 1]) {
      d[cur][avail + 1] = d[cur][avail] + price[cur];
      q.push(edge(cur, d[cur][avail + 1], avail + 1));
    }
  }
}

int
main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &price[i]);
    for (int i = 0; i < m; ++i) {
      int a, b, w;
      scanf("%d %d %d", &a, &b, &w);
      road[a].push_back(path(b, w));
      road[b].push_back(path(a, w));
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int src, dest;
      scanf("%d %d %d", &cap, &src, &dest);
      dijkstra(src);
      bool imp = true;
      int ans = INT_MAX;
      for (int j = 0; j <= cap && imp; ++j) {
        ans = min(ans, d[dest][j]);
      }
      if (ans == INT_MAX) printf("impossible\n");
      else printf("%d\n", ans);
    }
  }
  return 0;
}
