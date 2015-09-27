// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 405;
int n;
map <string, int> m;
vector <int> progs;
vector <string> con[MAXN];
vector <int> g[MAXN];
bool seen[MAXN];

bool
program(string s) {
  if (s.size() < 9) return false;
  return (s.substr(s.size() - 9, 9) == "::PROGRAM");
}

void
build_graph() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < con[i].size(); ++j) {
      string calls_me = con[i][j];
      if (m.count(calls_me)) g[m[calls_me]].push_back(i);
    }
  }
}

void
dfs(int u) {
  seen[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (!seen[v]) dfs(v); 
  }
}

int
main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    seen[i] = false;
    string name; int trash;
    cin >> name >> trash;
    m[name] = i;
    if (program(name)) progs.push_back(i);
    for (int k = 0; k < trash; ++k) {
      string from; cin >> from;
      con[i].push_back(from);
    }
  }
  build_graph();
  for (int i = 0; i < progs.size(); ++i) if (!seen[progs[i]]) dfs(progs[i]);
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += (!seen[i]);
  cout << ans << endl;
  return 0;
}

