#include <bits/stdc++.h>

using namespace std;

int n, mod = 360000;
vector <int> angles[2];
vector <int> diffs[2];

// Needle   = diffs[0]
// Haystack = diffs[1]
bool kmp() {
  vector <int> border(n);
  border[0] = 0;
  for (int i = 1; i < n; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 && diffs[0][i] != diffs[0][border[i]])
      border[i] = border[border[i] - 1];
    if (diffs[0][i] == diffs[0][border[i]]) border[i]++;
  }
  int seen = 0;
  for (int i = 0; i < 2 * n; ++i) {
    while (seen > 0 && diffs[1][i % n] != diffs[0][seen])
      seen = border[seen - 1];
    if (diffs[1][i % n] == diffs[0][seen]) seen++;
    if (seen == n) return true;
  }
  return false;
}

int
main() {
  cin >> n;
  int xi;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
      cin >> xi;
      angles[k].push_back(xi);
    }
    sort(angles[k].begin(), angles[k].end());
    for (int i = 1; i < n; ++i) diffs[k].push_back(angles[k][i] - angles[k][i - 1]);
    diffs[k].push_back((mod + angles[k][0] - angles[k][n - 1]) % mod);
  }
  if (kmp()) puts("possible");
  else puts("impossible");
  return 0;
}
