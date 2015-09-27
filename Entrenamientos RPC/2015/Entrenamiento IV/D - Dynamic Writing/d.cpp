#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1000005;
const ll MOD = 1000000007LL;
ll dp[MAXN][MAXN];

void
buildd() {
  for (int i = 0; i < MAXN; ++i) dp[0][i] = dp[i][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    for (int j = 1; j < MAXN; ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
}

int
main() {
  //build();
  puts("YA");
  return 0;
}
