//Santiago Vanegas Gil.
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
const ll INF = 1LL << 60;
int t, n, e, m;
ll tl;
ll d[MAXN][MAXN];

int
main() {
  cin >> t; 
  while (t--) {
    cin >> n >> e >> tl >> m;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i == j) d[i][j] = 0LL; 
        else d[i][j] = INF;
      } 
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      ll w;
      cin >> a >> b >> w;
      d[a][b] = w;
    }
    
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        } 
      }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += (d[i][e] <= tl);
    cout << ans << endl;
    if (t) cout << endl;
  }
  return 0;
}
