#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector <int> g [MAXN];
int c [MAXN][MAXN];
int f [MAXN][MAXN];
int prev [MAXN];
int n, m;

inline int in(int node) { return node; }
inline int out(int node) { return n + node; }

void
connect (int i, int j, int cap, bool bidir){
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;    
  if (bidir) c[j][i] += cap; 
}

int
maxflow(int s, int t){
  int flow = 0;
  while (true) {
    for (int i = 0; i <= 2 * n; i++) prev[i] = -1;

    queue <int> q;
    q.push(s);
    prev[s] = -2;

    while (q.size() > 0){
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if (prev[v] == -1 and c[u][v] - f[u][v] > 0){
          q.push(v);
          prev[v] = u;
        }
      }
    }
    if (prev[t] == -1) break;

    int extra = 1 << 30;
    int end = t;
    while (end != s){
      int start = prev[end];
      extra = min(extra, c[start][end] - f[start][end]);
      end = start;
    }

    end = t;
    while (end != s){
      int start = prev[end];
      f[start][end] += extra;
      f[end][start] = -f[start][end];
      end = start;
    }
    flow += extra;
  }
  return flow;
}

int
main() {
  while (scanf("%d %d", &n, &m) && n) {
    for (int i = 0; i <= 2 * n; ++i) {
      g[i].clear();
      for (int j = 0; j <= 2 * n; ++j) {
        c[i][j] = 0;
        f[i][j] = 0;
      }
    }
    for (int i = 0; i < n - 2; ++i) {
      int node, cap;
      scanf("%d %d", &node, &cap);
      connect(in(node), out(node), cap, true);
    }
    connect(in(1), out(1), INT_MAX, true);
    connect(in(n), out(n), INT_MAX, true);
    for (int i = 0; i < m; ++i) {
      int j, k, d;
      scanf("%d %d %d", &j, &k, &d);
      connect(out(j), in(k), d, false);
      connect(out(k), in(j), d, false);
    }
    printf("%d\n", maxflow(1, n));
  }
  return 0;
}

