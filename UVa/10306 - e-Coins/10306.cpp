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

typedef pair <int, int> coin;
const int INF = 1 << 30;
const int MAXS = 302;
const int MAXM = 42;
int dp[MAXS][MAXS];
coin coins[MAXM];
int t, m, s;

int
main() {
  cin >> t;
  while (t--) {
    cin >> m >> s;
    for (int i = 0; i <= s; i++) {
      for (int j = 0; j <= s; j++) {
        dp[i][j] = INF; 
      } 
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      coins[i] = coin(x, y); 
    }
    
    dp[0][0] = 0;
    for (int k = 0; k < m; k++) {
      coin c = coins[k];
      for (int i = c.first; i <= s; i++) {
        for (int j = c.second; j <= s; j++) {
          dp[i][j] = min(dp[i][j], dp[i-c.first][j-c.second] + 1); 
        }
      }
    }
    
    int ans = INF;
    for (int i = 0; i <= s; i++) {
      for (int j = 0; j <= s; j++) {
        if (sqrt((i * i + j * j) * 1.0) == s * 1.0) {
          ans = min(ans, dp[i][j]);
        }
      }
    }
    if (ans >= INF) cout << "not possible" << endl;
    else cout << ans << endl;
  }
  return 0;
}
