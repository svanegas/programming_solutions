#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int t, n, m;
vector <int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
stack <int> s;
bool stacked[MAXN];
int ticks, current_scc;
int enter[MAXN];

void tarjan(int u) {
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  for (int k = 0; k < g[u].size(); ++k) {
    int v = g[u][k];
    if (d[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
    else if (stacked[v]) low[u] = min(low[u], low[v]);
  }
  if (d[u] == low[u]) {
    int v;
    do {
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }
    while (u != v);
    current_scc++;
  }
}

int
main() {
  cin >> t;
  int z = 1;
  while (t--) {
    cin >> n >> m;
    while (!s.empty()) s.pop();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        g[i].clear();
      }
      d[i] = -1;
      enter[i] = 0;
      stacked[i] = false;
    }
    ticks = current_scc = 0;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
      if (d[i] == -1) tarjan(i);
    }


    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        if (scc[i] != scc[g[i][j]]) enter[scc[g[i][j]]]++;
      }
    }
    int ans = 0;
    for (int i = 0; i < current_scc; ++i) {
      ans += enter[i] == 0;
    }
    printf("Case %d: %d\n", z++, ans);
  }
  return 0;
}
