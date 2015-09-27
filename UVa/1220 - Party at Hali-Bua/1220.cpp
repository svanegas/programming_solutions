// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
int memo[MAXN][2], usol[MAXN][2];
map <string, int> m;
string boss[MAXN];
vector <int> g[MAXN];

int
c(int v, bool taken) {
  usol[v][taken] = true;
  if (g[v].empty()) return taken;
  if (memo[v][taken] != -1) return memo[v][taken];
  if (taken) {
    int ans = 1;
    for (int i = 0; i < g[v].size(); ++i) {
      ans += c(g[v][i], false);
      usol[v][taken] &= usol[g[v][i]][false];
    }
    return memo[v][taken] = ans;
  }
  else {
    int ans = 0;
    for (int i = 0; i < g[v].size(); ++i) {
      int a = c(g[v][i], true), b = c(g[v][i], false);
      usol[v][taken] &= (a == b ? false : usol[g[v][i]][a > b]);
      ans += max(a, b);
    }
    return memo[v][taken] = ans;
  }
}

int
main() {
  int n;
  while (cin >> n && n) {
    m.clear();
    for (int i = 0; i <= n; ++i) {
      memo[i][0] = memo[i][1] = -1;
      g[i].clear();
    }
    string name;
    cin >> name;
    m[name] = 0;
    for (int i = 1; i < n; ++i) {
      cin >> name >> boss[i];
      m[name] = i;
    }
    for (int i = 1; i < n; ++i) {
      int id = m[boss[i]];
      g[id].push_back(i); 
    }
    int a = c(0, true);
    int b = c(0, false);
    bool unique = (a == b ? false : usol[0][a > b]);
    cout << max(a, b) << " " << (unique ? "Yes" : "No") << endl;
  }
  return 0;
}

