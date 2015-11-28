#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXL = 2005;
map <string, int> m;
int speaks[MAXN];
set <int> under[MAXL];
vector <int> g[MAXN];

int
lan(string name) {
  if (m.count(name)) return m[name];
  else return m[name] = m.size();
}

int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack <int> s;
int ticks, current_scc;

void
tarjan(int u) {
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  for (int k = 0; k < g[u].size(); ++k) {
    int v = g[u][k];
    if (d[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
    else if (stacked[v]) low[u] = min(low[u], low[v]);
  }
  if (d[u] == low[u]) {
    int v;
    do {
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }
    while (u != v);
    current_scc++;
  }
}

int
main() {
  int n; cin >> n;
  for (int i = 0; i <= n; ++i) {
    d[i] = -1;
    stacked[i] = false;
  }
  ticks = 0;
  current_scc = 0;
  for (int i = 0; i < n; ++i) {
    string name, langu;
    cin >> name >> langu;
    int id_lan = lan(langu);
    speaks[i] = id_lan;
    under[id_lan].insert(i);
    string line; getline(cin, line);
    stringstream ss(line);
    while (ss >> langu) {
      int id = lan(langu);
      under[id].insert(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    int i_speak = speaks[i];
    set <int> :: iterator it;
    for (it = under[i_speak].begin(); it != under[i_speak].end(); ++it) {
      if (i != *it) g[i].push_back(*it);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (d[i] == -1) tarjan(i);
  }
  vector <int> comp(current_scc, 0);
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    comp[scc[i]]++;
    maxi = max(maxi, comp[scc[i]]);
  }
  cout << n - maxi << endl;
  return 0;
}
