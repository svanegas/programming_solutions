#include <bits/stdc++.h>

using namespace std;

int
main() {
  int t; cin >> t;
  while (t--) {
    bool solved = true;
    int n; cin >> n;
    int sq = (int) round(sqrt(n));
    set <int> sr[n];
    set <int> sg[sq][sq];
    for (int i = 0; i < n; ++i) {
      set <int> s;
      for (int j = 0; j < n; ++j) {
         int xi; cin >> xi;
         s.insert(xi);
         sr[j].insert(xi);
         sg[i / sq][j / sq].insert(xi);
      }
      solved &= s.size() == n;
    }
    for (int i = 0; i < n; ++i) solved &= sr[i].size() == n;
    for (int i = 0; i < sq; ++i) {
     for (int j = 0; j < sq; ++j) solved &= sg[i][j].size() == n; 
    }
    if (solved) puts("yes");
    else puts("no");
  }
  return 0;
}
