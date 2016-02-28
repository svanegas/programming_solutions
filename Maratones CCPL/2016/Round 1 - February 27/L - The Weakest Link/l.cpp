#include <bits/stdc++.h>

using namespace std;

int booth(const string &str) {
  string s = str + str;
  int n = s.size();
  vector <int> f(n, -1);
  int k = 0;
  for (int j = 1; j < n; ++j) {
    int i = f[j - k - 1];
    while (i != -1 && s[j] != s[k + i + 1]) {
      if (s[j] < s[k + i + 1]) k = j - i - 1;
      i = f[i];
    }
    if (i == -1 && s[j] != s[k + i + 1]) {
      if (s[j] < s[k + i + 1]) k = j;
      f[j - k] = -1;
    }
    else f[j - k] = i + 1;
  }
  return k;
}

int
main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << booth(s) + 1 << endl; 
  }
  return 0;
}
