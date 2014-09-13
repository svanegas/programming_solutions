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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 31;
const ll INF = 1LL << 60;
typedef pair <pair <int, int>, ll> edge;
vector <edge> g[MAXN][MAXN];
ll d[MAXN][MAXN];
int W, H, G, E;
int field[MAXN][MAXN];

bool
bellman_ford(int sX, int sY) {
  for (int i = 0; i <= W; i++) for (int j = 0; j <= H; j++) d[i][j] = INF;
  d[sX][sY] = 0;
  
  for (int i = 1; i <= (W * H) - 1; i++) {
    for (int u = 0; u < W; u++) {
      for (int l = 0; l < H; l++) {
        //Ignore unreacheable negative cycles
        if (d[u][l] == INF) continue;
        for (int k = 0; k < g[u][l].size(); k++) {
          int vX = g[u][l][k].first.first;
          int vY = g[u][l][k].first.second;
          ll w = g[u][l][k].second;
          d[vX][vY] = min(d[vX][vY], d[u][l] + w);
        }
      }
    } 
  }
  for (int u = 0; u < W; u++) {
    for (int l = 0; l < H; l++) {
      //Ignore unreacheable negative cycles
      if (d[u][l] == INF) continue;
      for (int k = 0; k < g[u][l].size(); k++) {
        int vX = g[u][l][k].first.first;
        int vY = g[u][l][k].first.second;
        ll w = g[u][l][k].second;
        if (d[vX][vY] > d[u][l] + w) return true; 
      } 
    }
  }
  return false;
}

int
main() {
  while (cin >> W >> H && W && H) {
    for (int i = 0; i <= W; i++) {
      for (int j = 0; j <= H; j++) {
        field[i][j] = 0; 
        g[i][j].clear();
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
      int x, y, x1, y1;
      ll peso;
      cin >> x >> y >> x1 >> y1 >> peso;
      field[x][y] = 2;
      g[x][y].push_back(edge(make_pair(x1, y1), peso));
    }
    for (int i = 0; i < W; i++) {
      for (int j = 0; j < H; j++) {
        //No edges leaving the exit cell
        if (i == W - 1 && j == H - 1) continue;
        if (field[i][j] == 0) {
          if (i - 1 >= 0 && field[i-1][j] != 1) {
            g[i][j].push_back(edge(make_pair(i-1, j), 1LL));
          }
          if (i + 1 < W && field[i+1][j] != 1) {
            g[i][j].push_back(edge(make_pair(i+1, j), 1LL));
          }
          if (j - 1 >= 0 && field[i][j-1] != 1) {
            g[i][j].push_back(edge(make_pair(i, j-1), 1LL));
          }
          if (j + 1 < H && field[i][j+1] != 1) {
            g[i][j].push_back(edge(make_pair(i, j+1), 1LL));
          }
        }
      } 
    }
    if (bellman_ford(0, 0)) {
      puts("Never");
    }
    else {
      if (d[W-1][H-1] < INF) cout << d[W-1][H-1] << endl;
      else cout << "Impossible" << endl;
    }
  }
  return 0;
}
