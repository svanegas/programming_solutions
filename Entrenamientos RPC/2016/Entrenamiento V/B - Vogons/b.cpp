#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 303;
int n, m, i, j;
ll xi, incl, excl, excl_new;
vector <ll> v[MAXN];

ll
solve(int ind) {
  incl = v[ind][0];
  excl = 0LL;
  for (i = 1; i < v[ind].size(); ++i) {
    excl_new = (incl > excl) ? incl : excl;
    incl = excl + v[ind][i];
    excl = excl_new; 
  }
  return ((incl > excl) ? incl : excl);
}

int
main() {
  while (scanf("%d %d", &n, &m) == 2) {
    for (i = 0; i < m; ++i) v[i].clear();
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        xi; scanf("%lld", &xi);
        v[j].push_back(xi); 
      } 
    }
    v[m].clear();
    for (j = 0; j < m; ++j) {
      v[m].push_back(solve(j));
    }
    printf("%lld\n", solve(m));
  }
  return 0;
}
