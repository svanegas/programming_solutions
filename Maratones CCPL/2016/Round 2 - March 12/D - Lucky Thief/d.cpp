#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll
sum(ll n) {
  return (n * (n + 1LL) / 2LL);
}

int
main() {
  int t; cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    cout << sum(m - 1LL) - sum(m - n - 1LL) << endl;
  }
  return 0;
}
