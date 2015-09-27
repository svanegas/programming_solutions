// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
const int MAXS = 105;
int piece[MAXN][MAXS];
int cut[MAXS];
int n, s, w, h;

int
main() {
  scanf("%d %d %d %d", &n, &s, &w, &h);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", &piece[i][j]);
    }
  }
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < w; ++j) {
      int a; scanf("%d", &a);
      a = h - a;
      cut[j] = (i == 0 ? a : min(cut[j], a));
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d", min(piece[i][0], cut[0]));
    for (int j = 1; j < w; ++j) {
      printf(" %d", min(piece[i][j], cut[j]));
    }
    printf("\n");
  }
  return 0;
}

