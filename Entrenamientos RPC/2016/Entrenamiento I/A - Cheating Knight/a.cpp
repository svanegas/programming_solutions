#include <bits/stdc++.h>

using namespace std;

int t, d, x, y;

int
main() {
  cin >> t;
  while (t--) {
    cin >> d >> x >> y;
    int num = x * x + y * y;
    int den = d;
    double ans = sqrt(num * 1.0 / den * 1.0);
    if (x * x + y * y > 0 && x * x + y * y < d) cout << 2 << endl;
    else cout << ((int) ceil(ans)) << endl;
  }
  return 0;
}
