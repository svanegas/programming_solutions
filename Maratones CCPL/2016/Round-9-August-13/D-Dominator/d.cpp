#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector <int> g[MAXN];
bool visited[MAXN];
bool seen[MAXN];
int t, n;

void
dfs(int s) {
  visited[s] = true;
  for (int i = 0; i < g[s].size(); ++i) {
    if (!visited[g[s][i]]) dfs(g[s][i]); 
  }
}

void
dfs2(int s) {
  seen[s] = true;
  for (int i = 0; i < g[s].size(); ++i) {
    if (!seen[g[s][i]]) dfs2(g[s][i]); 
  }
}

int
main() {
  int z = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int a; cin >> a;
        if (a) g[i].push_back(j);
      } 
    }
    memset(visited, false, sizeof visited);
    dfs(0);
    printf("Case %d:\n", z++);
    printf("+");
    for (int j = 0; j < n - 1; ++j) printf("--");
    printf("-+\n|");
    for (int j = 0; j < n; ++j) {
      printf("%c|", visited[j] ? 'Y' : 'N');
    }
    puts("");
    for (int i = 1; i < n; ++i) {
      memset(seen, false, sizeof seen);
      if (visited[i])  {
        seen[i] = true;
        dfs2(0);
      }
      printf("+");
      for (int j = 0; j < n - 1; ++j) printf("--");
      printf("-+\n|");
      for (int j = 0; j < n; ++j) {
        if (j == 0) printf("N|");
        else if (i == j) printf("%c|", visited[j] ? 'Y' : 'N');
        else printf("%c|", (visited[i] && visited[j] && !seen[j]) ? 'Y' : 'N');
      }
      puts("");
    }
    printf("+");
    for (int j = 0; j < n - 1; ++j) printf("--");
    printf("-+\n");
  }
  return 0;
}
