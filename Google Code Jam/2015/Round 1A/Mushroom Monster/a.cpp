#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int t, n, y, z, diff;
int m[MAXN];

int
main() {
  cin >> t;
  for (int c = 1; c <= t; ++c) {
    y = z = diff = 0;
    cin >> n;
    cin >> m[0];
    for (int i = 1; i < n; ++i) {
      cin >> m[i];
      y += max(0, m[i - 1] - m[i]);
      diff = max(diff, m[i - 1] - m[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
      z += min(m[i], diff);
    }
    printf("Case #%d: %d %d\n", c, y, z);
  }
  return 0;
}
