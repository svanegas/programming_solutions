// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

struct edge {
  // to node "to" using "with" edge.
  int to, with;
  edge() {}
  edge(int _to, int _with) : to(_to), with(_with) { }
};

const int INF = 1 << 30;
const int MAXN = 25;
vector <edge> g[MAXN];
int d[MAXN];
vector <int> f[MAXN][MAXN];
vector <int> c[MAXN][MAXN];
vector <int> p[MAXN][MAXN];
edge prev[MAXN];
int ans_price, ans_flow;

void
connect(int i, int j, int cap, int price) {
  f[i][j].push_back(0);
  f[j][i].push_back(0);
  p[i][j].push_back(price);
  p[j][i].push_back(-price);
  c[i][j].push_back(cap);
  c[j][i].push_back(0);
  g[i].push_back(edge(j, f[i][j].size() - 1));
  g[j].push_back(edge(i, f[i][j].size() - 1));
  assert(f[i][j].size() == f[j][i].size());
  assert(p[i][j].size() == p[j][i].size());
  assert(c[i][j].size() == c[j][i].size());
  assert(f[i][j].size() == p[i][j].size());
  assert(p[i][j].size() == c[i][j].size());
}

// s = fuente, t = sumidero, n = número de nodos
void
maxflow(int s, int t, int n) {
  // for (int i = 0; i <= n; i++) d[i] = INF;

  ans_flow = ans_price = 0;
  while (true) {
    for (int i = 0; i <= n; i++) {
      d[i] = INF;
      prev[i] = edge(-1, -1);
    }
    
    // Find augmenting path using Bellman-Ford.
    prev[s] = edge(-2, -2);
    d[s] = 0;
    for (int i = 1; i <= n - 1; ++i) {
      for (int u = 0; u < n; ++u) {
        for (int k = 0; k < g[u].size(); ++k) {
          int to = g[u][k].to;
          int with = g[u][k].with;
          int w = p[u][to][with];
          int cap = c[u][to][with];
          int flo = f[u][to][with];
          if (d[u] + w < d[to] && cap - flo > 0) {
            d[to] = d[u] + w;
            prev[to] = edge(u, with);
          }
        }
      }
    }
    
    if (prev[t].to == -1) break;
    
    int extra = INF;
    int end = t;
    while (end != s) {
      int start = prev[end].to;
      int with = prev[end].with;
      extra = min(extra, c[start][end][with] - f[start][end][with]);
      end = start;
    }

    end = t;
    while (end != s) {
      int start = prev[end].to;
      int with = prev[end].with;
      int pr = p[start][end][with];
      if (f[start][end][with] < 0) {
        int ret = min(extra, -f[start][end][with]);
        ans_price -= (ret * pr);
        int add = max(0, extra + f[start][end][with]);
        ans_price += (add * pr);
      }
      else ans_price += (pr * extra); 
      f[start][end][with] += extra;
      f[end][start][with] = -f[start][end][with];
      end = start;
    }
    ans_flow += extra;
  }
}

int
main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        f[i][j].clear();
        p[i][j].clear();
        c[i][j].clear();
      }
      g[i].clear();
    }
    int source = n;
    for (int i = 0; i < n - 1; ++i) {
      int ti; scanf("%d", &ti);
      connect(source, i, ti, 0);
    }
    for (int i = 0; i < m; ++i) {
      int a, b, w, pr;
      scanf("%d %d %d %d", &a, &b, &w, &pr);
      a--; b--;
      connect(a, b, w, pr);
      connect(b, a, w, pr);
    }
    maxflow(source, n - 1, n + 1);
    printf("%d %d\n", ans_flow, ans_price);
  }
  return 0; 
}
