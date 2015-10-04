// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
enum { ROW, COL };
map <string, int> vars_slvd;
set <string> vars;
string board[MAXN][MAXN];
int sol[MAXN][2];
bool solved[MAXN][2];
int n, m;

bool
solve(int where, int type) {
  int acum = 0;
  string incog = "..";
  int times = 0;
  for (int i = 0; i < (type == ROW ? m : n); ++i) {
    string cur = (type == ROW ? board[where][i] : board[i][where]);
    if (vars_slvd.count(cur) == 0) {
      if (incog != cur && incog != "..") {
        return false;
      }
      incog = cur;
      times++;
    }
    else acum += vars_slvd[cur];
  }
  if (incog == "..") return false;
  else {
    int incog_ans = (sol[where][type] - acum) / times;
    vars_slvd[incog] = incog_ans;
    solved[where][type] = true;
    return true;
  }
}

void
go() {
  int hey = vars_slvd.size();
  int hey_prev = -1;
  while (vars_slvd.size() < vars.size()) {
    assert(hey > hey_prev);
    bool got_sol = false;
    for (int i = 0; i < n && !got_sol; ++i) {
      if (!solved[i][ROW]) got_sol = solve(i, ROW);
    }
    for (int i = 0; i < m && !got_sol; ++i) {
      if (!solved[i][COL]) got_sol = solve(i, COL);
    }
    hey_prev = hey;
    hey = vars_slvd.size();
  }
}

int
main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    vars.clear();
    vars_slvd.clear();
    for (int i = 0; i <= max(n, m); ++i) solved[i][ROW] = solved[i][COL] = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        string var = "..";
        scanf("%*c %c %c", &var[0], &var[1]);
        board[i][j] = var;
        vars.insert(var);
      }
      scanf("%d", &sol[i][ROW]);
    }
    for (int j = 0; j < m; ++j) scanf("%d", &sol[j][COL]);
    go();
    map <string, int> :: iterator it;
    for (it = vars_slvd.begin(); it != vars_slvd.end(); ++it) {
      printf("%s %d\n", (it->first).c_str(), it->second);
    }
  }
  return 0;
}
