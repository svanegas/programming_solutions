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

const int MAXN = 5005;
const int MAXS = 12;
int t, n;
double dp[MAXS][MAXN];

int
main() {
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      dp[i][j] = (j * 1.0) / (i * 1.0);
    }
  }
  double ans = 0.0;
  for (int i = 1; i <= 10; ++i) {
    cout << dp[i][10] << " ";
    ans += dp[i][10];
  }
  cout << endl;
  cout << "ans: " << ans / 10.0 << endl;
  return 0;
}
