#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int
parse(int i, int j) {
  return (i * m) + j;
}

int
unhapp(int mask) {
  int un = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int ind = parse(i, j);
      if ((1 << ind) & (
      if (j + 1 < m) {
        
      }
    }
  }
}

int
solve(int mask, int turn, int cur) {
  if (cur >= n * m && turn < n * m) return INF;
  else if (turn >= n * m) {
    
  }
  int ans = INT_MAX;
  for (int i = cur; i < n * m; ++i) {
    int next = mask;
    next |= (1 << i);
    ans = min(ans, solve(next, turn + 1, i + 1));
  }
}

int
main() {
  scanf("%d", &t);
  for (int z = 1; z <= t; ++z) {
    
  }
  return 0;
}
