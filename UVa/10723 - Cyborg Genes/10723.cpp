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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 35;
int c, n, m;
string s, t;
int dp[MAXN][MAXN];
int ways[MAXN][MAXN];

void
solve() {
  for (int i = 0; i <= n; i++) dp[i][0] = 0, ways[i][0] = 1;
  for (int j = 0; j <= m; j++) dp[0][j] = 0, ways[0][j] = 1;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        ways[i][j] = ways[i-1][j-1];
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        ways[i][j] = 0;
        if (dp[i][j] == dp[i-1][j]) ways[i][j] += ways[i-1][j]; 
        if (dp[i][j] == dp[i][j-1]) ways[i][j] += ways[i][j-1];
      }
    } 
  }
}

int
main() {
  cin >> c;
  getchar();
  for (int cas = 1; cas <= c; cas++) {
    //cin >> s >> t;
    getline(cin, s);
    getline(cin, t);
    n = s.size(), m = t.size();
    solve();
    printf("Case #%d: %d %d\n", cas, (n + m) - dp[n][m], ways[n][m]);
  }
  return 0;
}
