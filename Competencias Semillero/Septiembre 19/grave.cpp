//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }



typedef long long ll;
struct edge {
  int destX, destY;
  ll weight;
  edge (int DX, int DY, ll W) : destX(DX), destY(DY), weight(W) {}  
};
const ll INF = 1LL << 60;
const int MAXN = 35;
int n, m, g, e;
int grass[MAXN][MAXN];
ll d[MAXN][MAXN];
vector <edge> graph[MAXN][MAXN];
enum grassType {GRASS, GRAVE, HOLE};

void
build_graph() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == n - 1 && j == m - 1) break;
      if (grass[i][j] == GRASS) {
        if (i > 0 && grass[i-1][j] != GRAVE) 
          graph[i][j].push_back(edge(i-1, j, 1LL));
        if (i < n - 1 && grass[i+1][j] != GRAVE)
          graph[i][j].push_back(edge(i+1, j, 1LL));
        if (j > 0 && grass[i][j-1] != GRAVE)
          graph[i][j].push_back(edge(i, j-1, 1LL)); 
        if (j < m - 1 && grass[i][j+1] != GRAVE)
          graph[i][j].push_back(edge(i, j+1, 1LL)); 
      }
    } 
  }
}

bool
bellman_ford(int sI, int sJ) {
  d[sI][sJ] = 0LL;
  
  for (int i = 1; i <= ((n * m) - g) - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < m; ++v) {
        if (d[u][v] == INF) continue;
        for (int k = 0; k < graph[u][v].size(); ++k) {
          int nextI = graph[u][v][k].destX;
          int nextJ = graph[u][v][k].destY;
          ll w = graph[u][v][k].weight;
          d[nextI][nextJ] = min(d[nextI][nextJ], d[u][v] + w);
        } 
      } 
    } 
  }
  
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < m; ++v) {
      for (int k = 0; k < graph[u][v].size(); ++k) {
        if (d[u][v] >= INF) continue;
        int nextI = graph[u][v][k].destX;
        int nextJ = graph[u][v][k].destY;
        ll w = graph[u][v][k].weight;
        if (d[nextI][nextJ] > d[u][v] + w) return true;
      }
    }
  }
  return false;
}

int
main() {
  while (scanf("%d %d", &n, &m) != EOF && n && m) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        grass[i][j] = GRASS;
        d[i][j] = INF;
        graph[i][j].clear();
      } 
    }
    scanf("%d", &g);
    for (int i = 0; i < g; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      grass[x][y] = GRAVE; 
    }
    scanf("%d", &e);
    for (int i = 0; i < e; ++i) {
      int x1, y1, x2, y2;
      ll t;
      scanf("%d %d %d %d %lld", &x1, &y1, &x2, &y2, &t);
      grass[x1][y1] = HOLE;
      graph[x1][y1].push_back(edge(x2, y2, t));
    }
    build_graph();
    if (bellman_ford(0, 0)) printf("Never\n");
    else if (d[n-1][m-1] == INF) printf("Impossible\n");
    else printf("%d\n", d[n-1][m-1]);
  }
  return 0;
}
