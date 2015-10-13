// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35;
vector <int> box[MAXN];
vector <int> g[MAXN];
int d[MAXN], prev[MAXN];
int n, k;

void
dfs(int u, stack <int> &st) {
  d[u] = 1;
  for (int i = 0; i < g[u].size(); ++i) {
    int next = g[u][i];
    if (d[next] == -1) dfs(next, st);
  }
  st.push(u);
}

void
build_topo(stack <int> &s) {
  for (int i = 0; i <= n; ++i) d[i] = -1;
  for (int i = 0; i < n; ++i) {
    if (d[i] == -1) dfs(i, s);
  }
}

pair <int, int>
bfs(int src) {
  d[src] = 1, prev[src] = -2;
  queue <int> q;
  q.push(src);
  int ans = d[src], ending = src;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i];
      if (d[cur] + 1 > d[next]) {
        d[next] = d[cur] + 1;
        if (d[next] > ans) {
          ending = next;
          ans = d[next];
        }
        prev[next] = cur;
        q.push(next);
      }
    }
  }
  return make_pair(ans, ending);
}

pair <int, int>
solve(stack <int> &s) {
  for (int i = 0; i < n; ++i) {
    d[i] = -1;
    prev[i] = -1;
  }
  int ans = 0, ending = -1;
  for (int i = 0; i < n; ++i) {
    int next = s.top(); s.pop();
    if (d[next] == -1) {
      pair <int, int> val = bfs(next);
      if (val.first > ans) {
        ans = val.first;
        ending = val.second;
      }
    }
  }
  return make_pair(ans, ending);
}


bool
can(int a, int b) {
  for (int i = 0; i < k; ++i) {
    if (box[b][i] <= box[a][i]) return false;
  }
  return true;
}

int
main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    for (int i = 0; i < n; ++i) {
      box[i].clear();
      g[i].clear();
      for (int j = 0; j < k; ++j) {
        int ki; scanf("%d", &ki);
        box[i].push_back(ki);
      }
      sort(box[i].begin(), box[i].end());
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && can(i, j)) {
          g[i].push_back(j);
        }
      }
    }
    stack <int> s;
    build_topo(s);
    pair <int, int> ans = solve(s);
    printf("%d\n", ans.first);
    stack <int> path;
    int p = ans.second, u;
    do {
      u = p;
      p = prev[u];
      path.push(u + 1);
    }
    while (p != -2);
    printf("%d", path.top());
    path.pop();
    while (!path.empty()) {
      printf(" %d", path.top());
      path.pop();
    }
    puts("");
  }
  return 0;
}
