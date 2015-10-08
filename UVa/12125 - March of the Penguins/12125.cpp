// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int INF = 1 << 30;
struct point {
  int x, y, peng, times;
  point() {}
  point(int _x, int _y, int _p, int _t) : x(_x), y(_y), peng(_p), times(_t) { }
};
int n, tot_peng;
double d;
vector <point> points;
vector <int> g[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int prev[MAXN];

int
out(int node) {
  return node >= 2 * n ? node : n + node;
}

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

void
connect(int i, int j, int cap) {
  g[out(i)].push_back(j);
  g[j].push_back(out(i));
  c[out(i)][j] += cap;
}

void
merge(int i, int cap) {
  g[i].push_back(out(i));
  g[out(i)].push_back(i);
  c[i][out(i)] += cap;
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
  while (t--) {
    scanf("%d %lf", &n, &d);
    for (int i = 0; i <= 2 * n + 1; ++i) {
      for (int j = 0; j <= 2 * n + 1; ++j) c[i][j] = 0;
      g[i].clear();
    }
    points.clear();
    tot_peng = 0;
    int source = 2 * n;
    for (int i = 0; i < n; ++i) {
      point p = point();
      scanf("%d %d %d %d", &p.x, &p.y, &p.peng, &p.times);
      tot_peng += p.peng;
      points.push_back(p);
      if (p.peng > 0) connect(source, i, p.peng);
      if (p.times > 0) merge(i, p.times);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (dist(points[i], points[j]) <= d) {
          connect(i, j, INF);
          connect(j, i, INF);
        }
      }
    }
    bool printed = false;
    for (int i = 0; i < n; ++i) {
      if (maxflow(source, i, 2 * n + 1) == tot_peng) {
        if (printed) printf(" ");
        printf("%d", i);
        printed = true;
      }
    }
    if (printed) puts("");
    else puts("-1");
  }
  return 0;
}
