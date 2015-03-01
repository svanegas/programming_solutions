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

struct point {
  int x, y;
  point (int X, int Y) : x(X), y(Y) { }
};

inline int distsqr(const point &a, const point &b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); 
}

inline double dist(const point &a, const point &b) {
  return sqrt(distsqr(a, b));  
}

const int MAXN = 1115; //100 trees, (10+1) branches, 10 doctors + 5 extra
int t, n, m, k, d, z;
vector <int> g[MAXN];
vector <point> points;
int w[MAXN];

void
bfs(int s) {
  for (int i = 0; i <= z; ++i) w[i] = -1;
  queue <int> q;
  q.push(s);
  w[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i];
      if (w[next] == -1) {
        w[next] = w[cur] + 1;
        q.push(next);
      } 
    } 
  }
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k >> d;
    z = 0;
    for (int i = 0; i <= (n * 10) + m + 3; ++i) g[i].clear();
    points.clear();
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      points.push_back(point(x, y));
      z++;
    }
    for (int i = 0; i < n; ++i) {
      int b; cin >> b;
      vector <point> tree;
      for (int j = 0; j < b; ++j) {
        int x, y;
        cin >> x >> y;
        point p = point(x, y);
        if (j > 0) {
          int a = z, b = z - 1;
          g[a].push_back(b);
          g[b].push_back(a);
        }
        for (int l = 0; l < points.size(); ++l) {
          double distnc = dist(p, points[l]);
          if (l >= m && distnc <= k) {
            g[z].push_back(l);
            g[l].push_back(z);
          }
          if (l < m && distnc <= d) {
            g[z].push_back(l);
            g[l].push_back(z);
          }
        }
        tree.push_back(p);
        z++;
      }
      points.insert(points.end(), tree.begin(), tree.end());
    }
    bfs(m);
    bool can = false;
    for (int i = 0; i < m && !can; ++i) if (w[i] != -1) can = true;
    if (can) cout << "Tree can be saved :)" << endl;
    else cout << "Tree can't be saved :(" << endl;
  }
  return 0;
}
