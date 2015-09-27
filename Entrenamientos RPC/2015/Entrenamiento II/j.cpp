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

const int MAXN = 12;
int n;
double conv[MAXN][MAXN];
map <string, int> m;

void
fill(int a, int b, double am) {
  conv[a][b] = am;
  conv[b][a] = 1.0 / am;
}

void
update(int a, int b, double am) {
  for (int i = 0; i < n; ++i) {
    if (i != b && conv[i][a] != -1) {
      if (am > conv[i][a]) update(i, b, conv[i][a] / am);
      else update(i, b, conv[i][a] * am);
    }
  }
}

int
main() {
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) conv[i][j] = 1.0;
        else conv[i][j] = -1.0;
      }
    }
    string buff1, buff2, trash;
    for (int i = 0; i < n; ++i) {
      cin >> buff1;
      m[buff1] = i;
    }
    for (int i = 0; i < n - 1; ++i) {
      double amount;
      cin >> buff1 >> trash >> amount >> buff2;
      fill(m[buff1], m[buff2], amount);
      if (i == 0) continue;
      update(m[buff1], m[buff2], amount);
    }
  }
  return 0;
}

