#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int
main() {
  ll n;
  while (cin >> n) {
    ll ans = 0;
    while (n > 1LL) {
      ans += (n / 2LL);
      n = (n / 2LL) + (n % 2LL);
    }
    cout << ans << endl;
  }
  return 0;
}
