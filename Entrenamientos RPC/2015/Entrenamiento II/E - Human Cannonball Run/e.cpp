#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <limits>
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
  double x, y;
  point() {}
  point(double X, double Y) : x(X), y(Y) { }
};

inline double dist(const point &a, const point &b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

const int MAXN = 105;
const double INF = numeric_limits <double>::max();
typedef pair <double, int> dist_node; // Datos del heap (dist, nodo)
typedef pair <int, double> edge; // Dato de las arista (nodo, peso)
vector <edge> g[MAXN];        // g[u] = (v = nodo, w = peso)
double d[MAXN];    // d[u] La distancia más corta de s a u
int n;
vector <point> points;

// La función recibe la fuente s y el número total de nodos n
void dijkstra(int s) {
  for (int i = 0; i <= n; ++i) d[i] = INF;
  priority_queue < dist_node, vector <dist_node>, 
                  greater<dist_node> > q;
  d[s] = 0.0;
  q.push(dist_node(0.0, s));
  while (!q.empty()){
    double dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i){
      int next = g[cur][i].first;
      double w_extra = g[cur][i].second;
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        q.push(dist_node(d[next], next));
      }
    }
  }  
}


void
build_graph() {
  n += 2;
  point a, b;
  for (int i = 0; i < n; ++i) {
    if (i == 1) continue;
    for (int j = 1; j < n; ++j) {
      a = points[i];
      b = points[j];
      double w = dist(a, b);
      g[i].push_back(edge(j, w / 5.0));
      if (i == 0) continue;
      double time = 0.0;
      time += (abs(w - 50.0) / 5.0);
      time += 2.0;
      g[i].push_back(edge(j, time));
    }
  }
}

int
main() {
  double x, y;
  scanf("%lf %lf", &x, &y);
  points.push_back(point(x, y));
  scanf("%lf %lf", &x, &y);
  points.push_back(point(x, y));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf %lf", &x, &y);
    points.push_back(point(x, y));
  }
  build_graph();
  dijkstra(0);
  printf("%lf\n", d[1]);
  return 0;
}

