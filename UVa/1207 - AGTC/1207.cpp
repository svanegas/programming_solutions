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

const int MAXN = 5005;
string s, t;
int n, m;
int dp[MAXN][MAXN];

int
solve() {
  for (int j = 0; j <= m; j++) dp[0][j] = j; 
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
      else {
        dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  return dp[n][m];
}

int
main() {
  while (cin >> n >> s >> m >> t) {
    cout << solve() << endl;
  }
  return 0; 
}
