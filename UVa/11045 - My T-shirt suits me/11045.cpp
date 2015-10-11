// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 6;
const int MAXM = 30;
const int MAXX = MAXN + MAXM + 7;
vector <int> g[MAXX];
int c[MAXX][MAXX];
int f[MAXX][MAXX];
int prev[MAXX];
int t;

void
connect(int i, int j, int cap) {
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;
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
  scanf("%d", &t);
  map <string, int> type;
  type["XXL"] = 0; type["XL"] = 1; type["L"] = 2;
  type["M"] = 3; type["S"] = 4; type["XS"] = 5;
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int source = MAXN + m; int dest = source + 1;
    for (int i = 0; i <= dest + 1; ++i) {
      for (int j = 0; j <= dest + 1; ++j) {
        c[i][j] = 0;
      }
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      char buff1[5], buff2[5];
      scanf("%s %s", &buff1[0], &buff2[0]);
      int from1 = type[string(buff1)];
      int from2 = type[string(buff2)];
      connect(from1, MAXN + i, 1);
      connect(from2, MAXN + i, 1);
      connect(MAXN + i, dest, 1);
    }
    for (int i = 0; i < MAXN; ++i) connect(source, i, n / 6);
    if (maxflow(source, dest, dest + 1) == m) puts ("YES");
    else puts("NO");
  }
  return 0;
}
