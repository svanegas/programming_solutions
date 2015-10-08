// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 1025;
vector <int> g[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int prev[MAXN];

void
connect(int i, int j, int cap){
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;
}

int
maxflow(int s, int t, int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = 0;
    }
  }
  int flow = 0;
  while (true) {
    for (int i = 0; i <= n; i++) prev[i] = -1;
    queue <int> q;
    q.push(s);
    prev[s] = -2;
    while (q.size() > 0){
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if (prev[v] == -1 and c[u][v] - f[u][v] > 0){
          q.push(v);
          prev[v] = u;
        }
      }
    }
    if (prev[t] == -1) break;
    int extra = INF;
    int end = t;
    while (end != s) {
      int start = prev[end];
      extra = min(extra, c[start][end] - f[start][end]);
      end = start;
    }
    end = t;
    while (end != s) {
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
  int np, nc;
  while (scanf("%d %d", &nc, &np) && np) {
    int n = np + nc + 2;
    int source = np + nc;
    int dest = source + 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) c[i][j] = 0;
      g[i].clear();
    }
    int expected = 0;
    for (int i = 0; i < nc; ++i) {
      int ci; scanf("%d", &ci);
      connect(np + i, dest, ci);
      expected += ci;
    }
    for (int i = 0; i < np; ++i) {
      connect(source, i, 1);
      int num_cat; scanf("%d", &num_cat);
      for (int j = 0; j < num_cat; ++j) {
        int to_cat; scanf("%d", &to_cat);
        connect(i, np + to_cat - 1, 1);
      }
    }
    if (maxflow(source, dest, n) == expected) {
      puts("1");
      for (int j = 0; j < nc; ++j) {
        bool printed = false;
        for (int i = 0; i < np; ++i) {
          if (f[i][np + j] == 1) {
            if (printed) printf(" ");
            printf("%d", i + 1);
            printed = true;
          }
        }
        puts("");
      }
    }
    else puts("0");
  }
  return 0;
}
