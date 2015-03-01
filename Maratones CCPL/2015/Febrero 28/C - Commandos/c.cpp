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
const int MAXN = 105;
const ll INF = 1LL << 30;
int t, n, m, dep, dest, z;
ll ans;
ll d[MAXN][MAXN];

void
floyd() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
      }
    }
  }
}

int
main() {
  z = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) d[i][j] = INF;
        else d[i][j] = 0LL;
      }
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      d[a][b] = 1LL;
      d[b][a] = 1LL;
    }
    cin >> dep >> dest;
    floyd();
    ans = 0LL;
    for (int i = 0; i < n; ++i) ans = max(ans, d[dep][i] + d[i][dest]);
    printf("Case %d: %lld\n", z++, ans);
  }
  return 0;
}
