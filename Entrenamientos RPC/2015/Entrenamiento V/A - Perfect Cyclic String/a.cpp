#include <bits/stdc++.h>

using namespace std;

int t;

int solve(const string &needle){
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;
  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]])
      border[i] = border[border[i] - 1];
    if (needle[i] == needle[border[i]]) border[i]++;
  }
  int base = m - border[m - 1];
  if (m % base == 0) return base;
  else return m;
}

int
main() {
  cin >> t;
  while (t--) {
    string word;
    cin >> word;
    cout << solve(word) << endl;
  }
}
