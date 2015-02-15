#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
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

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 100005;
ll fact[MAXN];

void
build() {
  fact[0] = 0LL;
  fact[1] = 1LL;
  for (int i = 2; i <= 100001; ++i) fact[i] = (i * (fact[i - 1] % MOD)) % MOD;
}

int t, n;

int
main() {
  build();
  cin >> t;
  while (t--) {
    cin >> n;
    printf("%lld\n", fact[n] - 1);
  }
  return 0;
}

