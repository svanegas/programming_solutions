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
state memo[MAXN][MAXN];

state
lps2(const string &seq, int i, int j) {
  if (i == j) return state(1, is_spec[i]);
  if (seq[i] == seq[j] && i + 1 == j) return state(2, is_spec[i] + is_spec[j]);
  if (memo[i][j].len != -1) return memo[i][j];
  if (seq[i] == seq[j]) {
    state ret = lps2(seq, i + 1, j - 1);
    ret.len += 2;
    ret.spec += (is_spec[i] + is_spec[j]);
    state option = max(lps2(seq, i, j - 1), lps2(seq, i + 1, j));
    return memo[i][j] = max(ret, option);
  }
  return memo[i][j] = max(lps2(seq, i, j - 1), lps2(seq, i + 1, j));
}

int
main() {
  ios::sync_with_stdio(false);
  string s; int n;
  while (cin >> s >> n) {
    for (int i = 0; i <= s.size(); ++i) {
      is_spec[i] = false;
      for (int j = 0; j <= s.size(); ++j) memo[i][j] = state(-1, -1);
    }
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      is_spec[x - 1] = true;
    }
    cout << lps2(s, 0, s.size() - 1).len << endl;
  }
  return 0;
}
