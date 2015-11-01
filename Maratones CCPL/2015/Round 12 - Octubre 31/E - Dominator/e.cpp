#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector <int> g[MAXN];
int n;
bool vis[2][MAXN];

void
dfs(int s, int pos, int supI) {
  if (s == supI) return;
  vis[pos][s] = true;
  for (int i = 0; i < g[s].size(); ++i) {
    int next = g[s][i];
    if (!vis[pos][next]) {
      dfs(next, pos, supI);
    }
  }
}

void
printLine() {
  printf("+-");
  for (int i = 0; i < n - 1; ++i) {
    printf("--");
  }
  printf("+\n");
}

int main() {
  int t; cin >> t;
  int z = 1;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      vis[0][i] = vis[1][i] = false;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int xi; cin >> xi;
        if (xi) g[i].push_back(j);
      }
    }
    dfs(0, 0, -1);
    printf("Case %d:\n", z++);
    printLine();
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k <= n; ++k) vis[1][k] = false;
      dfs(0, 1, i);
      printf("|");
      for (int j = 0; j < n; ++j) {
        printf("%c|", vis[1][j] || !vis[0][j] ? 'N' : 'Y');
      }
      puts("");
      printLine();
    }
  }
  return 0;
}

/*
2
5
0 1 1 0 0
0 0 0 1 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
1
1
*/
