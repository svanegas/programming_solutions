// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 10005;
int n, m;
typedef pair <int, int> edge;
vector <edge> g[MAXN];
int d[MAXN];

void
dijkstra(int src) {
  priority_queue <edge, vector <edge>, greater <edge> > q;
  q.push(edge(0, src));
  d[src] = 0;
  while (!q.empty()) {
    int cur = q.top().second;
    int w = q.top().first; q.pop();
    if (w > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i].second;
      int w_extra = g[cur][i].first;
      for (int j = 0; j < g[next].size(); ++j) {
        int even = g[next][j].second;
        int w_even = g[next][j].first;
        if (w + w_extra + w_even < d[even]) {
          d[even] = w + w_extra + w_even;
          q.push(edge(d[even], even));
        }
      }
    }
  }
}

int
main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i <= n; ++i) {
      d[i] = INF;
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int a, b, w;
      scanf("%d %d %d", &a, &b, &w);
      a--; b--;
      g[a].push_back(edge(w, b));
      g[b].push_back(edge(w, a));
    }
    dijkstra(0);
    printf("%d\n", d[n - 1] == INF ? -1 : d[n - 1]);
  }
  return 0;
}
