#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int p[MAXN];
int o[MAXN];
int sum[MAXN];

void initialize(int n) {
  for (int i = 0; i <= n; ++i) {
    p[i] = i;
    sum[i] = 0;
  }
}

int findd(int u) {
  if (p[u] == u) return u;
  return p[u] = findd(p[u]);
}

void join(int u, int v) {
  int a = findd(u);
  int b = findd(v);
  if (a == b) return;
  p[a] = b;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    initialize(n);
    for (int i = 0; i < n; ++i) cin >> o[i];
    for (int j = 0; j < m; ++j) {
      int a, b;
      cin >> a >> b;
      join(a, b);
    }
    for (int i = 0; i < n; ++i) sum[findd(i)] += o[i];
    bool can = true;
    for (int i = 0; i < n && can; ++i) {
      can &= (sum[i] == 0);
    }
    if (can) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
  }
  return 0;
}
