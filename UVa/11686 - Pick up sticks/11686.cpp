// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

enum color {WHITE, GRAY, BLACK};
const int MAXN = 1000005;
vector <int> g[MAXN];
stack <int> topo_sort;
int n, m;
int d[MAXN];

bool
dfs(int u) {
  d[u] = GRAY;
  bool can = true;
  for (int i = 0; can && i < g[u].size(); ++i) {
    int v = g[u][i];
    if (d[v] == GRAY) can = false;
    else if (d[v] == WHITE) can &= dfs(v);
  }
  d[u] = BLACK;
  topo_sort.push(u);
  return can;
}

int
main() {
  while (scanf("%d %d", &n, &m) && (n || m)) {
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      d[i] = WHITE; 
    }
    while (!topo_sort.empty()) topo_sort.pop();
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      g[a].push_back(b); 
    }
    bool can = true;
    for (int i = 0; can && i < n; ++i) {
      if (d[i] == WHITE) can &= dfs(i);
    }
    if (can) {
      while (!topo_sort.empty()) {
        printf("%d\n", topo_sort.top() + 1);
        topo_sort.pop();
      }
    }
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}

