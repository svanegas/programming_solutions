#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n) {
  ll ans = 24LL;
  ans += (n * n * n * n);
  ans -= (6LL * n * n * n);
  ans += (23LL * n * n);
  ans -= (18LL * n);
  return ans / 24LL;
}

int
main() {
  int t; cin >> t;
  while (t--) {
    ll xi; cin >> xi;
    cout << solve(xi) << endl; 
  }
  return 0;
}
