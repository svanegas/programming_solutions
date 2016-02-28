#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2005;
const ll MOD = 9999959999LL;
ll memo[MAXN / 2][MAXN];

ll
calc(int l, int r) {
  if (memo[l][r] != -1) return memo[l][r];
  ll ans = 0LL;
  if (l == 0 && r == 0) return 1LL;
  if (l >= 1 && r >= 1) {
    ans += (1LL + calc(l - 1, r + 1));
    ans %= MOD;
    ans += calc(l, r - 1);
    return memo[l][r] = ans % MOD;
  }
  if (l >= 1) {
    ans += (1LL + calc(l - 1, r + 1));
    return memo[l][r] = ans % MOD;
  }
  if (r >= 1) {
    ans += (1LL + calc(l, r - 1));
    return memo[l][r] = ans % MOD;
  }

}

int
main() {
  int l, r;
  for (int i = 0; i <= 1001; ++i) {
    for (int j = 0; j <= 2001; ++j) memo[i][j] = -1;
  }
  while (cin >> l >> r && (l || r)) cout << calc(l, r) << endl;
  return 0;
}
