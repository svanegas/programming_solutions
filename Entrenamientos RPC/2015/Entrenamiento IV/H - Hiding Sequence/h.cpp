#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;
map <ll, int> m;
ll dp[MAXN], ans;
int n;

int
main() {
  scanf("%d", &n);
  ans = dp[0] = 0LL;
  for (int i = 1; i <= n; ++i) {
    ll xi;
    scanf("%lld", &xi);
    dp[i] = dp[i - 1] + xi;
    ans += (dp[i] == 0LL);
    ans += (m[dp[i]]);
    m[dp[i]]++;
  }
  printf("%lld\n", ans);
  return 0;
}
