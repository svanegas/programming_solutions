// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 10;
const int MAXM = 25;
const int MAXX = MAXN * (MAXM * 2) + MAXN + 5;
int has[MAXX][MAXX];
vector <int> g[MAXX];
int c[MAXX][MAXX];
int f[MAXX][MAXX];
int prev[MAXX];

int
in(int i, int k, int stickers) {
  return i * stickers + k;
}

int
out(int i, int k, int n, int stickers) {
  return (i * stickers + k) + (n * stickers);
}

int
source(int who, int n, int stickers) {
  return 2 * n * stickers + who;
}

int
sink(int who, int n, int stickers) {
  if (who != 0) return source(who, n, stickers);
  else return source(n - 1, n, stickers) + 1;
}

void
connect(int i, int j, int cap) {
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;
}

void
clean(int n, int m) {
  int nodes = sink(0, n, m) + 1;
  for (int i = 0; i <= nodes; ++i) {
    for (int j = 0; j <= nodes; ++j) {
      c[i][j] = 0;
      has[i][j] = 0;
    }
    g[i].clear();
  }
}

int
maxflow(int s, int t, int nn) {
  for (int i = 0; i <= nn; i++){
    for (int j = 0; j <= nn; j++){
      f[i][j] = 0;
    }
  }
  int flow = 0;
  while (true) {
    for (int i = 0; i <= nn; i++) prev[i] = -1;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if (prev[v] == -1 && c[u][v] - f[u][v] > 0){
          q.push(v);
          prev[v] = u;
        }
      }
    }
    if (prev[t] == -1) break;
    int extra = INF;
    int end = t;
    while (end != s){
      int start = prev[end];
      extra = min(extra, c[start][end] - f[start][end]);
      end = start;
    }
    end = t;
    while (end != s){
      int start = prev[end];
      f[start][end] += extra;
      f[end][start] = -f[start][end];
      end = start;
    }
    flow += extra;
  }
  return flow;
}

int
main() {
  int t;
  scanf("%d", &t);
  for (int z = 1; z <= t; ++z) {
    int n, m;
    scanf("%d %d", &n, &m);
    clean(n, m);
    for (int i = 0; i < n; ++i) {
      int k; scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
        int ki; scanf("%d", &ki);
        ki--;
        has[i][ki]++;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        // Connect source to out sticker if I'm willing to give it.
        if (has[i][j] > 1) connect(source(i, n, m), out(i, j, n, m), has[i][j] - 1);
        // Connect in sticker to sink if I'm willing to receive it.
        if (has[i][j] == 0) connect(in(i, j, m), sink(i, n, m), 1);
      }
    }
    // Connect outs with ins
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < m; ++k) {
        for (int j = 0; j < n; ++j) {
          if (i != j) connect(out(i, k, n, m), in(j, k, m), 1);
        }
      }
    }
    int base_ans = 0;
    for (int k = 0; k < m; ++k) base_ans += (has[0][k] > 0);
    printf("Case #%d: %d\n", z, base_ans + maxflow(source(0, n, m),
                             sink(0, n, m), sink(0, n, m) + 1));
  }
  return 0;
}
