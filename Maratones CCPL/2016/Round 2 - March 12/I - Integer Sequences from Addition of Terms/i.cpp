#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <double> v;

ll poww(int b, int exp) {
  if (exp == 0) return 1LL;
  ll ans = b * 1LL;
  for (int i = 1; i < exp; ++i) ans *= (1LL * b);
  return ans;
}

int
main() {
  int C;
  double vi, d, k;
  ll res, n;
  cin >> C;
  while (C--) {
     v.clear();
     int it; cin >> it;
     for (int i = 0; i <= it; ++i) {
        cin >> vi;
        v.push_back(vi);
     }
     cin >> d >> k;
     double sq = sqrt(1.0 + ((8.0 * k) / d));
     double num = 1 + sq;
     n = ((ll) ceil(num / 2.0));
     n--;
     res = 0LL;
     for (int j = 0; j < v.size(); ++j) {
        ll pw = poww(n, j);
        res += ((ll) v[j]) * pw;
     }
     cout << res << endl;
   }
}
