// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int n, r;
int score[MAXN];

int
main() {
  while (scanf("%d %d", &n, &r) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &score[i]);
    for (int k = 1; k < r; ++k) {
      for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        score[i] += x;
      }
    }
    int maxi = score[0];
    int winn = 1;
    for (int i = 1; i < n; ++i) {
      if (score[i] >= maxi) {
        winn = i + 1;
        maxi = score[i];
      }
    }
    printf("%d\n", winn);
  }
  return 0;
}
