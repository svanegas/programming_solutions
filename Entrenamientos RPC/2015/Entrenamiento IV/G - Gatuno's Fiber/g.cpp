#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(T x) {
  stringstream ss; ss << x; return ss.str();
}

template <class T> int toInt(T x) {
  stringstream ss; ss << x; int r; ss >> r; return r;
}

const int MAXN = 35;
int n;
char sym[MAXN];

void
build() {
  sym[0] = '!';
  sym[1] = '@';
  sym[2] = '#';
  sym[3] = '$';
  sym[4] = '%';
  sym[5] = '&';
  for (int i = 'a'; i <= 'z'; ++i) sym[i - 91] = (char) i;
}

string
binValue(int x) {
  string res = "";
  while (x > 0) {
    res += toStr(x % 2);
    x /= 2;
  }
  while (res.size() < 8) res += "0";
  reverse(res.begin(), res.end());
  return res;
}

int
intValue(int x) {
  int ans = 0;
  int i = 0;
  while (x > 0) {
    ans += ((1 << i++) * (x % 10));
    x /= 10;
  }
  return ans;
}

int
main() {
  build();
  string trace = "";
  while (cin >> n) {
    trace += binValue(n);
  }
  while (trace.size() % 5 != 0) trace += "0";
  int printed = 0;
  for (int i = 0; i < trace.size(); i += 5) {
    if (printed != 0 && printed % 80 == 0) cout << endl;
    string bits = trace.substr(i, 5);
    int val = toInt(bits);
    cout << sym[intValue(val)];
    printed++;
  }
  cout << endl;
  return 0;
}
