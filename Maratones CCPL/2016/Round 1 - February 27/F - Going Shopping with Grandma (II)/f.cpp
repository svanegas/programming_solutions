#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 205;
double memo1[MAXN / 2][MAXN];
double memo2[MAXN / 2][MAXN][MAXN + 100];

double
calc(int l, int r) {
  if (memo1[l][r] != -1.0) return memo1[l][r];
  double ans = 1.0;
  if (l == 0) return r * 1.0;
  double pL = (l * 1.0) / ((l + r) * 1.0);
  double pR = (r * 1.0) / ((l + r) * 1.0);
  if (l >= 1 && r >= 1) {
    ans = pL * calc(l - 1, r + 1);
    ans += pR * calc(l, r - 1);
    return memo1[l][r] = ans;
  }
  if (l >= 1) {
    ans = pL * calc(l - 1, r + 1);
    return memo1[l][r] = ans;
  }
}

double
calc2(int l, int r, int h) {
  if (memo2[l][r][h] != -1.0) return memo2[l][r][h];
  double ans = 1.0;
  if (l == 0) return h * 1.0;
  double pL = (l * 1.0) / ((l + r) * 1.0);
  double pR = (r * 1.0) / ((l + r) * 1.0);
  if (l >= 1 && r >= 1) {
    ans = pL * calc2(l - 1, r + 1, h + 1);
    ans += pR * calc2(l, r - 1, h + 1);
    return memo2[l][r][h] = ans;
  }
  if (l >= 1) {
    ans = pL * calc2(l - 1, r + 1, h + 1);
    return memo2[l][r][h] = ans;
  }
}

int
main() {
  int l, r;
  for (int i = 0; i <= 101; ++i) {
    for (int j = 0; j <= 201; ++j) {
      memo1[i][j] = -1.0;
      for (int k = 0; k <= 301; ++k) {
        memo2[i][j][k] = -1.0;
      }
    }
  }
  while (cin >> l >> r && (l || r)) {
    printf("%.12f %.12f\n", calc(l, r), calc2(l, r, 0));
  }
  return 0;
}
