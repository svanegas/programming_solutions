// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int t, n, m, l;
vector <int> g[MAXN];
enum color {WHITE, GRAY, BLACK};
int d[MAXN];

void
dfs(int u) {
  d[u] = GRAY;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i]; 
    if (d[v] == WHITE) dfs(v);
  }
  d[u] = BLACK;
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> l;
    for (int i = 0; i <= n; ++i) {
      d[i] = WHITE;
      g[i].clear(); 
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
    }
    for (int i = 0; i < l; ++i) {
      int z;
      cin >> z; z--;
      if (d[z] == WHITE) dfs(z);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += (d[i] == BLACK);
    cout << ans << endl;
  }
  return 0;
}

