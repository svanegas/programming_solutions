// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

int memo[5][5];
int n, m;

bool
can_go(int from, int to, int mask) {
  int iniI = from / m, iniJ = from % m;
  int finI = to / m, finJ = to % m;
  if (abs(iniI - finI) == 2 && abs(iniJ - finJ) == 1) return true;
  if (abs(iniI - finI) == 1 && abs(iniJ - finJ) == 2) return true;
  int incrI = iniI <= finI ? iniI == finI ? 0 : 1 : -1;
  int incrJ = iniJ <= finJ ? iniJ == finJ ? 0 : 1 : -1;
  bool can = true;
  for (int i = iniI + incrI, j = iniJ + incrJ; i != finI || j != finJ; i += incrI, j += incrJ) {
    int ind = m * i + j;
    if (!(mask & (1 << ind))) can = false;
  }
  return can;
}

int
solve(int cur, int mask) {
  mask |= (1 << cur);
  int ans = 1;
  if (mask == (1 << (n * m)) - 1) return ans;
  for (int i = 0; i < n * m; ++i) {
    if (!(mask & (1 << i))) {
      if (can_go(cur, i, mask)) ans += solve(i, mask);;
    }
  }
  return ans;
}

int
main() {
  for (n = 1; n <= 3; ++n) {
    for (m = n; m <= 3; ++m) {
      memo[n][m] = 0;
      for (int k = 0; k < n * m; ++k) memo[n][m] += solve(k, 0);
    }
  }
  int z = 1;
  while (scanf("%d %d", &n, &m) && n) {
    printf("Case #%d: %d\n", z++, memo[min(n, m)][max(n, m)]);
  }
  return 0;
}
