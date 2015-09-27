// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

string
parse(const string &s) {
  string res = "";
  for (int i = 0; i < s.size(); ++i) {
    if (isdigit(s[i])) {
      res += ".";
      ++i;
      while (i < s.size() && isdigit(s[i])) ++i;
      --i;
    }
    else if (isalpha(s[i])) res += ".";
    else if (s[i] == '(' || s[i] == ')') res += s[i];
    else res += "*";
  }
  return res;
}

int
kmp(const string &needle, const string &haystack) {
  int ans = 0;
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;

  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]])
      border[i] = border[border[i] - 1];
    if (needle[i] == needle[border[i]]) border[i]++;
  }

  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > 0 and haystack[i] != needle[seen])
      seen = border[seen - 1];
    if (haystack[i] == needle[seen]) seen++;
    if (seen == m)  ans++;
  }
  return ans;
}

int
main() {
  ios::sync_with_stdio(false);
  string s, t;
  while (cin >> s >> t) {
    string a = parse(s);
    string b = parse(t);
    cout << kmp(a, b) << endl;
  }
  return 0;
}
