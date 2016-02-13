#include <bits/stdc++.h>

using namespace std;

int t, n, avail, min_avail, ans, fuel, dist;

int
main() {
  cin >> t;
  while (t--) {
    avail = min_avail = 0;
    ans = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      if (avail < min_avail) {
        ans = i + 1;
        min_avail = avail;
      }
      cin >> fuel >> dist;
      avail += (fuel - dist);
    }
    if (avail < 0) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
  }
  return 0;
}
