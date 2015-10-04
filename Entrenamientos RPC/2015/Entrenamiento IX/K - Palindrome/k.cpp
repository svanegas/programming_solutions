// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

struct state {
  int len, spec;
  state() {}
  state(int _len, int _spec) : len(_len), spec(_spec) {}
  bool operator < (const state &than) const {
    if (spec < than.spec) return true;
    else if (spec == than.spec) return len < than.len;
    else return false;
  }
};
const int MAXN = 2005;
bool is_spec[MAXN];
state dp[MAXN][MAXN];

int
lps(const string &str) {
  int n = str.size();
  int i, j, cl, interest;
  for (i = 0; i < n; ++i) dp[i][i] = state(1, is_spec[i]);
  for (cl = 2; cl <= n; ++cl) {
    for (i = 0; i < n - cl + 1; ++i) {
      j = i + cl - 1;
      if (str[i] == str[j] && cl == 2) {
        interest = is_spec[i] + is_spec[j];
        dp[i][j] = state(2, interest);
      }
      else if (str[i] == str[j]) {
        interest = is_spec[i] + is_spec[j];
        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        dp[i][j] = max(dp[i][j], state(dp[i+1][j-1].len + 2, dp[i+1][j-1].spec + interest));
      }
      else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
    }
  }
  return dp[0][n - 1].len;
}

int
main() {
  ios::sync_with_stdio(false);
  string s; int n;
  while (cin >> s >> n) {
    for (int i = 0; i <= s.size(); ++i) is_spec[i] = false;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      is_spec[x - 1] = true;
    }
    cout << lps(s) << endl;
  }
  return 0;
}
