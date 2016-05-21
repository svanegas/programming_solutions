#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int
main() {
  int t; cin >> t;
  while (t--) {
    vector <int> v;
    int n;
    ll w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
      ll xi; cin >> xi;
      v.push_back(xi);
    }
    sort(v.begin(), v.end());
    ll cur = 0LL;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (cur + v[i] <= w) {
        cur += v[i];
        ans++;
      }
      else break;
    }
    cout << ans << endl;
  }
  return 0;
}
