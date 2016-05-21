#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int num[30];

int
parse(int x) {
  string res = toStr(x);
  for (int i = 0; i < res.size(); ++i) {
    if (res[i] == '2') res[i] = '5';
    else if (res[i] == '5') res[i] = '2';
    else if (res[i] == '6') res[i] = '9';
    else if (res[i] == '9') res[i] = '6';
  }
  return toInt(res);
}

int
main() {
  string s;
  while (cin >> s) {
    for (char i = 'a'; i <= 'z'; ++i) num[i - 'a'] = -1; 
    int z = 1;
    for (int i = 0; i < s.size(); ++i) {
      int cur = s[i] - 'a';
      if (num[cur] == -1) num[cur] = parse(z++);
      cout << num[cur];
    }
    cout << endl;
  }
  return 0;
}
