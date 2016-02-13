#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
int t, n, m, po, c;
int p[MAXN * MAXN];
bool has[MAXN * MAXN];

int num(int i, int j) {
  return i * m + j;
}

void initialize() {
  for (int i = 0; i <= n * m; ++i) {
    p[i] = i;
    has[i] = false;
  }
}

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void join(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return;
  p[a] = b;
  has[a] = has[b] = has[a] | has[b];
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> po >> c;
    initialize();
    for (int i = 0; i < po; ++i) {
      int x, y; cin >> x >> y;
      has[num(x, y)] = true;
    }
    for (int i = 0; i < c; ++i) {
      int x, y;
      char dir;
      cin >> x >> y >> dir;
      if (dir == 'R') join(num(x, y), num(x + 1, y));
      if (dir == 'U') join(num(x, y), num(x, y + 1));
    }
    set <int> comps;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int caca = find(num(i, j));
        comps.insert(find(num(i, j)));
      }
    }
    int ans = 0;
    set <int> :: iterator it;
    for (it = comps.begin(); it != comps.end(); ++it) {
      ans += has[*it] == false;
    }
    cout << ans << endl;
  }
  return 0;
}
