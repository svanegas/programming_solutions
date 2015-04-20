#include <bits/stdc++.h>

using namespace std;

int t;
string s, mini;

int
main() {
  cin >> t;
  while (t--) {
    mini = "Z";
    cin >> s;
    int sz = s.size();
    s += s;
    for (int i = 0; i < sz; ++i) {
      mini = min(mini, s.substr(i, sz));
    }
    cout << mini << endl;
  }  
  return 0;
}
