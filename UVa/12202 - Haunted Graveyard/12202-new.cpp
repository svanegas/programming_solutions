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

struct edge {
  int x, y, w;
  edge (int X, int Y, int W) : x(X), y(Y), w(W) {}  
};

const int INF = 1 << 30;
const int MAXN = 33;
int n, m, G, E;
int field[MAXN][MAXN];
vector <edge> g[MAXN][MAXN];
int d[MAXN][MAXN];

void
buildGraph() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == n - 1 && j == m - 1) continue;
      if (field[i][j] == 0) {
        if (i - 1 >= 0 && field[i-1][j] != 1) {
          g[i][j].push_back(edge(i-1, j, 1)); 
        }
        if (i + 1 < n && field[i+1][j] != 1) {
          g[i][j].push_back(edge(i+1, j, 1)); 
        }
        if (j - 1 >= 0 && field[i][j-1] != 1) {
          g[i][j].push_back(edge(i, j-1, 1)); 
        }
        if (j + 1 < m && field[i][j+1] != 1) {
          g[i][j].push_back(edge(i, j+1, 1)); 
        }
      }
    } 
  }  
}

bool
bellman_ford() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      d[i][j] = INF;
    } 
  }
  d[0][0] = 0;
  
  for (int i = 1; i < n * m - G; i++) {
    for (int u = 0; u < n; u++) {
      for (int l = 0; l < m; l++) {
        if (d[u][l] >= INF) continue;
        for (int k = 0; k < g[u][l].size(); k++) {
          int vX = g[u][l][k].x;
          int vY = g[u][l][k].y;
          int w = g[u][l][k].w;
          d[vX][vY] = min(d[vX][vY], d[u][l] + w);
        } 
      } 
    } 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d[i][j] >= INF) continue;
      for (int k = 0; k < g[i][j].size(); k++) {
        int vX = g[i][j][k].x;
        int vY = g[i][j][k].y;
        int w = g[i][j][k].w;
        if (d[vX][vY] > d[i][j] + w) return true;
      }
    } 
  }
  return false;
}

int
main() {
  while (cin >> n >> m && n && m) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        g[i][j].clear();
        field[i][j] = 0;
      }
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
      int x, y;
      cin >> x >> y;
      field[x][y] = 1;
    }
    cin >> E;
    for (int i = 0; i < E; i++) {
      int x1, y1, x2, y2, t;
      cin >> x1 >> y1 >> x2 >> y2 >> t;
      g[x1][y1].push_back(edge(x2, y2, t));
      field[x1][y1] = 2;
    }
    buildGraph();
    if (bellman_ford()) puts("Never");
    else if (d[n-1][m-1] >= INF) puts("Impossible");
    else printf("%d\n", d[n-1][m-1]);
  }
  return 0;
}
