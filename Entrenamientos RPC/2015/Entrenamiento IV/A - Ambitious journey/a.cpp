#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int g[MAXN][MAXN], dp[MAXN][MAXN];
int n;

int
main() {
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = 0;
        scanf("%d", &g[i][j]);
      }
    }
    dp[0][0] = g[0][0];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i + 1 < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + g[i + 1][j]);
        if (j + 1 < n) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + g[i][j + 1]);
      }
    }
    printf("%d\n", dp[n - 1][n - 1]);
  }
  return 0;
}
