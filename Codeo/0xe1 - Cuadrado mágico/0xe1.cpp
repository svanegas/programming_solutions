#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 105;
int n;
ll m[MAXN][MAXN], diagonal1 = 0LL, diagonal2 = 0LL;

int
main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> m[i][j];
      if (i == j) diagonal1 += m[i][j];
      if (i == n - 1 - j) diagonal2 += m[i][j];
      if (i > 0) m[i][j] += m[i - 1][j];
      if (j > 0) m[i][j] += m[i][j - 1];
      // If both sides were > 0, it added the subrectangle ending in diagional
      // twice, subtract once.
      if (i > 0 && j > 0) m[i][j] -= m[i - 1][j - 1];
    }
  }

  // If diagonals are not the same, there's no solution.
  bool can = diagonal1 == diagonal2;
  // check all rows
  for (int i = 1; i < n && can; ++i) can &= diagonal1 == m[i][n - 1] - m[i - 1][n - 1];
  // check columns
  for (int j = 0; j < n && can; ++j) {
    ll val = m[n - 1][j];
    if (j > 0) val -= m[n - 1][j - 1];
    can &= diagonal1 == val;
  }

  if (can) cout << "Yes";
  else cout << "No";
  cout << endl;
  return 0;
}
