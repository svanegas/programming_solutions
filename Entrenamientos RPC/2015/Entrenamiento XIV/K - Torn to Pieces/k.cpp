#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35;
set <int> g[MAXN];
map <string, int> m;
bool seen[MAXN];
int p[MAXN];

int
ind(string name) {
  if (m.count(name)) return m[name];
  else return m[name] = m.size();
}

void
dfs(int src) {
  seen[src] = true;
  set <int> :: iterator it;
  for (it = g[src].begin(); it != g[src].end(); ++it) {
    int next = *it;
    if (!seen[next]) {
      p[next] = src;
      dfs(next);
    }
  }
}

string
g_name(int ind) {
  map <string, int> :: iterator it;
  for (it = m.begin(); it != m.end(); ++it) {
    if (it->second == ind) return it->first;
  }
  assert(false);
  return "NOT_FOUND";
}

int
main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string from; cin >> from;
    string line; getline(cin, line);
    string to;
    stringstream ss(line);
    int indFrom = ind(from);
    while (ss >> to) {
      int indTo = ind(to);
      g[indFrom].insert(indTo);
      g[indTo].insert(indFrom);
    }
  }
  string src, dest; cin >> src >> dest;
  for (int i = 0; i <= n; ++i) {
    seen[i] = false;
    p[i] = -1;
  }
  int iSrc = ind(src), iDest = ind(dest);
  dfs(iSrc);
  if (!seen[iDest]) puts("no route found");
  else {
    int cur = iDest;
    vector <string> path;
    while (cur != iSrc) {
      string naaa = g_name(cur);
      path.push_back(naaa);
      cur = p[cur];
    }
    path.push_back(g_name(iSrc));
    reverse(path.begin(), path.end());
    cout << path[0];
    for (int i = 1; i < path.size(); ++i) {
      cout << " " << path[i];
    }
    puts("");
  }
  return 0;
}
