#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
int scc[MAXN];
bool seen[MAXN];
int n, m, t;

void dfs1(int u) {
  seen[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (!seen[v]) dfs1(v);
  }
  topo_sort.push_back(u);
}

void dfs2(int u, int comp) {
  scc[u] = comp;
  for (int i = 0; i < grev[u].size(); ++i) {
    int v = grev[u][i];
    if (scc[v] == -1) dfs2(v, comp);
  }
}

int find_scc() {
  for (int u = 0; u < n; ++u) {
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i];
      grev[v].push_back(u);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!seen[i]) dfs1(i);
  }
  reverse(topo_sort.begin(), topo_sort.end());

  int comp = 0;
  for (int i = 0; i < n; ++i) {
    int u = topo_sort[i];
    if (scc[u] == -1) dfs2(u, comp++);
  }
  return comp;
}

int
main() {
  cin >> t;
  int z = 1;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      grev[i].clear();
      scc[i] = -1;
      seen[i] = false;
    }
    topo_sort.clear();
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
    }
    int comp = find_scc();
    vector <int> entries(comp, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        int neigh = g[i][j];
        if (scc[i] != scc[neigh]) entries[scc[neigh]]++;
      }
    }
    int ans = 0;
    for (int i = 0; i < comp; ++i) ans += (entries[i] == 0);
    printf("Case %d: %d\n", z++, ans);
  }
  return 0;
}
