#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int INF = 1 << 30;
vector <int> g[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int prev[MAXN];

inline int in(int i) {
  return i;  
}

inline int out(int i, int n) {
  return i + n;
}

void connect(int i, int j, int cap, bool bid) {
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;
  if (bid) c[j][i] += cap;  
}

int maxflow(int s, int t, int n) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      f[i][j] = 0; 
    } 
  }
  int flow = 0;
  while (true) {
    for (int i = 0; i <= n; ++i) prev[i] = -1;
    
    queue <int> q;
    q.push(s);
    prev[s] = -2;
    
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (prev[v] == -1 && c[u][v] - f[u][v] > 0) {
          q.push(v);
          prev[v] = u; 
        } 
      }
    }
    
    if (prev[t] == -1) break;
    
    int extra = 1 << 30;
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

void clear(int n) {
  for (int i = 0; i <= n; ++i) {
    g[i].clear();
    for (int j = 0; j <= n; ++j) {
      c[i][j] = 0;
    }
  }
}

int
main() {
  int m, w;
  while (cin >> m >> w && m) {
    clear(m * 2);
    for (int i = 0; i < m - 2; ++i) {
      int id, cap; cin >> id >> cap;
      id--;
      connect(in(id), out(id, m), cap, false);
    }
    for (int i = 0; i < w; ++i) {
      int a, b, cost; cin >> a >> b >> cost;
      a--; b--;
      connect(out(a, m), in(b), cost, false);
      connect(out(b, m), in(a), cost, false);
    }
    cout << maxflow(m, m - 1, m * 2) << endl;
  }
  return 0;
}
