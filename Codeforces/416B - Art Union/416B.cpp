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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 50005;
int n, m;
ll dp[5][MAXN];

int
main() {
  cin >> m >> n;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      cin >> dp[i][j];
      if (i == 0 && j > 0) dp[i][j] += dp[i][j-1];
      else if (i > 0 && j == 0) dp[i][j] += dp[i-1][j]; 
      else if (i > 0 && j > 0) dp[i][j] = max(dp[i-1][j] + dp[i][j], dp[i][j-1] + dp[i][j]); 
    } 
  }
  cout << dp[n-1][0];
  for (int j = 1; j < m; j++) {
    cout << " " << dp[n-1][j];
  }
  cout << endl;
  return 0;
}
