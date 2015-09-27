// Santiago Vanegas Gil
#include <bits/stdc++.h>
 
using namespace std;
 
string s;
 
inline int mid() {
  if (s.size() % 2 == 0) return s.size() / 2 - 1;
  else return s.size() / 2;
}
inline int esp(int i) {
  return i <= mid() ? s.size() - i - 1 : i;
}
 
void
add(int i) {
  if (i < 0) {
    if (s[0] == '0') {
      s = "1" + s;
      s[s.size() - 1] = s[0];
    }
    return;
  }
  if (s[i] == '9') {
    s[i] = s[esp(i)] = '0';
    add(i - 1);
  }
  else s[i] = s[esp(i)] = s[i] + 1;
}
 
void
next_pal() {
  for (int i = 0; i <= mid(); ++i) {
    if (s[i] < s[esp(i)]) {
      s[esp(i)] = s[i];
      add(esp(i) - 1);
    }
    else s[esp(i)] = s[i];
  }
}
 
void
go(int d) {
  for (int i = 0; i < d; ++i) {
    cout << s << endl;
    add(mid());
  }
}
 
int
main() {
  ios::sync_with_stdio(false);
  int d;
  string orig_s;
  while (cin >> d >> s) {
    orig_s = s;
    next_pal();
    if (orig_s == s) add(mid());
    go(d);
  }
  return 0;
}
