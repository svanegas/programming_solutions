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

typedef long long ll;
const int MAXN = 1005;
const ll MOD = 1000007LL;
int n, m;
ll dp[MAXN], sum[MAXN];

int
main() {
  dp[0] = 1LL;
  sum[0] = 1LL;
  for (int i = 1; i < MAXN; ++i) {
    dp[i] = ((dp[i - 1] % MOD) * 2LL) % MOD;
    sum[i] = ((sum[i - 1] % MOD) + (dp[i] % MOD)) % MOD;
  }
  while (scanf("%d %d", &n, &m) && n != -1) {
    ll ans = sum[m] % MOD;
    if (n - 1 >= 0) ans -= (sum[n-1] % MOD);
    printf("%lld\n", (ans + MOD) % MOD);
  }
}

