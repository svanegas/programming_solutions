// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll
conv(vector <int> num, int base) {
  ll ans = 0, mul = 1LL;
  for (int i = 0; i < num.size(); ++i) {
    ans += (num[i]) * mul;
    mul *= base; 
  }
  return ans;
}

vector <int>
deg(ll num, int base) {
  vector <int> ans;
  while (num > 0) {
    ans.push_back(num % base);
    num /= base;
  }
  return ans;
}

int
main() {
  int t;
  cin >> t;
  while (t--) {
    int b1, b2;
    ll r1, r2, ans = -1LL;
    cin >> b1 >> b2 >> r1 >> r2;
    for (ll i = r2 - 1LL; i > r1 && ans == -1LL; --i) {
      vector <int> x = deg(i, b1);
      ll y = conv(x, b2);
      if (y % i == 0LL) ans = i;
    }
    if (ans != -1LL) cout << ans << endl;
    else cout << "Non-existent." << endl;
  }
  return 0;
}

