#include <bits/stdc++.h>

using namespace std;

int t, n;
const int MAXN = 100005;
bool found[MAXN];

int
main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) found[i] = false;
    for (int i = 1; i < n; ++i) {
      int ind; scanf("%d", &ind);
      found[ind] = true;
    }
    for (int i = 1; i <= n; ++i) {
      if (!found[i]) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
