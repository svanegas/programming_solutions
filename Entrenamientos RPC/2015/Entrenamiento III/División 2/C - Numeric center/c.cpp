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

const int MAXN = 1000000;

bool
candidate(int x, int n) {
  int left = (n * (n + 1)) / 2;
  int right = (x * (x + 1)) / 2;
  int eq = (x * (x - 1)) / 2;
  return left - right == eq;
}

int
main() {
  for (int i = 1; i <= MAXN; ++i) {
    for (int j = 1; j <= MAXN; ++j) {
      if (candidate(j, i)) {
        cout << "mid: " << j << " to " << i << endl;
      }
    }
  }
  return 0;
}

