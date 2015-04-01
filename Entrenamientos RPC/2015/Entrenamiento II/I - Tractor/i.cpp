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

int t, a, b, ans, jmp;

int
main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ans = jmp = 1;
    for (int i = 1; i <= a + b; i += jmp) {
      ans += jmp * 2;
      if (a < i) ans -= (i - a);
      if (b < i) ans -= (i - b);
      jmp <<= 1;
    }
    cout << ans << endl;
  }
  return 0;
}

