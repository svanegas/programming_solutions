#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
int k, n;
int fav[MAXN];

int
main() {
  while (cin >> k >> n && k) {
    for (int i = 0; i < n; ++i) cin >> fav[i];
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i % fav[j] == 0) {
          ans++;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
