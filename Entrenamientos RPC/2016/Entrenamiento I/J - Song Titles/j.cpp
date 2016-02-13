#include <bits/stdc++.h>

using namespace std;

int t;
string title;
map <char, int> m;

// WRONG ANSWER, TRY THIS CASE:
// aaaaabbbbccc
// abababacacbc
int
main() {
  cin >> t;
  while (t--) {
    m.clear();
    cin >> title;
    for (int i = 0; i < title.size(); ++i) {
      m[title[i]]++;
    }
    char last = '-';
    string ans = "";
    map <char, int> :: iterator it1;
    map <char, int> :: iterator it2;
    while (m.size() >= 2) {
      it1 = m.begin();
      it2 = ++m.begin();
      ans += it1->first;
      ans += it2->first;
      (it1->second)--;
      (it2->second)--;
      if (it2->second == 0) {
        m.erase(it2);
      }
      if (it1->second == 0) {
        m.erase(it1);
      }
    }
    if (m.begin()->second > 1) cout << "IMPOSSIBLE" << endl;
    else cout << ans + (m.begin()->first) << endl;

  }
  return 0;
}
