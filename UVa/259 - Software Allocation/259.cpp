// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAXAPP = 26;
const int MAXPC = 10;
const int MAXN = MAXAPP + MAXPC + 5;
vector <int> g[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int prev[MAXN];
int ans[MAXN];
int source = MAXAPP + MAXPC;
int dest = source + 1;

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
      if (start < MAXAPP) ans[end] = start;
      f[start][end] += extra;
      f[end][start] = -f[start][end];
      end = start;
    }
    flow += extra;
  }
  return flow;
}

int
processJob(string job) {
  int app = job[0] - 'A';
  int ppl = job[1] - '0';
  connect(source, app, ppl);
  for (int i = 3; job[i] != ';'; ++i) {
    int pc = (job[i] - '0') + MAXAPP;
    connect(app, pc, 1);
  }
  return ppl;
}

int
main() {
  string line;
  while (getline(cin, line)) {
    for (int i = 0; i <= MAXAPP + MAXPC + 2; ++i) {
      for (int j = 0; j <= MAXAPP + MAXPC + 2; ++j) {
        c[i][j] = 0;
      }
      g[i].clear();
      ans[i] = -1;
    }
    int tot_jobs = 0;
    while (line != "") {
      tot_jobs += processJob(line);
      getline(cin, line);
    }
    for (int i = 0; i <= 9; ++i) connect(i + MAXAPP, dest, 1);
    if (maxflow(source, dest, MAXAPP + MAXPC + 2) == tot_jobs) {
      for (int i = 0; i <= 9; ++i) {
        printf("%c", ans[MAXAPP + i] == -1 ? '_' : 'A' + ans[MAXAPP + i]);
      }
      puts("");
    }
    else puts("!");
  }
  return 0;
}
