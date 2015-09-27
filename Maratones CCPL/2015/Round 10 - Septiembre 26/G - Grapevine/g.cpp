// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int n, m, q;
int h[MAXN][MAXN];

int
go(int lo, int hi) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int ind = lower_bound(&h[i][0], &h[i][m], lo) - &h[i][0];    
    for (int k = i + ans, j = ind + ans; k < n && j < m; ++k, ++j) {
      if (h[k][j] <= hi) ans++;
      else break;
    }
  }
  return ans;
}

int
main() {
  while(scanf("%d %d", &n, &m) && n && m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &h[i][j]);
      }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int lo, hi;
      scanf("%d %d", &lo, &hi);
      printf("%d\n", go(lo, hi));
    }
    puts("-");
  }
  return 0;
}

