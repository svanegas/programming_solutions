#include <iostream>
#include <vector>

using namespace std;

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
  cin >> s >> t;
  n = s.size(); m = t.size();
  cout << solve() << endl;
  return 0; 
}