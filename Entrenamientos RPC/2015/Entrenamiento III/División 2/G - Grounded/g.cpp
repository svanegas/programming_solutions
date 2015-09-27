#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const long double EPS = 1e-9;
const double PI = acos(-1.0);

int cmp(long double x, long double y = 0, long double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef vector <bool> str;
const int MAXN = 6;
int ans[MAXN][MAXN];
vector <str> table;
vector <vector <int> > p;

bool
build(str& bs) {
  for (int i = 0; i != bs.size(); ++i) {
    bs[i] = 1 - bs[i];
    if (bs[i]) return true;
  }
  return false;
}

vector <int>
ones(str s) {
  vector <int> res(s.size(), 0);
  for (int i = 0; i < s.size(); ++i) {
    res[i] += s[i];
  }
  return res;
}

void
solve() {
  for (int i = 0; i <= 4; ++i) for (int j = 0; j <= 4; ++j) ans[i][j] = 0;
  for (int n = 1; n <= 4; ++n) {
    table.clear();
    p.clear();
    str bs(n, 0);
    do {
      table.push_back(bs);
    }
    while (build(bs));
    vector <int> empty;
    empty.push_back(-1);
    p.push_back(empty);
    
    for (int i = 0; i < table.size(); ++i) {
      vector <vector <int> > addition;
      for (int j = 0; j < p.size(); ++j) {
        vector <int> cur = p[j];
        cur.push_back(i);
        addition.push_back(cur);
      }
      for (int u = 0; u < addition.size(); ++u) {
        p.push_back(addition[u]);
      }
    }
    for (int i = 0; i < p.size(); ++i) {
      vector <int> sum(n, 0);
      for (int j = 0; j < p[i].size(); ++j) {
        if (p[i][j] == -1) continue;
        vector <int> partial = ones(table[p[i][j]]);
        for (int l = 0; l < partial.size(); ++l) {
          sum[l] += partial[l];
        }   
      }
      int oneCount = 0;
      for (int l = 0; l < sum.size(); ++l) oneCount += (sum[l] == 1);
      for (int k = 0; k <= n; ++k) ans[n][k] += (oneCount == k);
    }
  }
}

int
main() {
  int n, k;
  solve();
  while (scanf("%d %d", &n, &k) != EOF) {
    printf("%d\n", ans[n][k]);
  }
  return 0;
}

