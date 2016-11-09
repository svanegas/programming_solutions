#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXM = 1000005;
const int MAXN = 30;
int w[MAXN];
int dp[MAXM];
int t, n, m;

void
build() {
  dp[0] = 0;
  for (int i = 1; i <= m; ++i) {
    dp[i] = INF;
    for (int j = 0; j < n; ++j) {
      if (i - w[j] >= 0) dp[i] = min(dp[i], dp[i - w[j]] + 1);
    }
  }
}

int
main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> w[i];
    build();
    cout << dp[m] << endl;
  }
  return 0;
}
