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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct Edge {
  int a, b;
  double w;
  Edge (int A, int B, double W) : a(A), b(B), w(W) {}  
  
  bool operator < (const Edge &than) const {
    return w < than.w; 
  }
};

struct Point {
  int x, y;
  Point (int X, int Y) : x(X), y(Y) {}  
};

double dist(const Point &a, const Point &b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));  
}

const int MAXN = 505;
int t, s, n;
vector <Point> points;
vector <Edge> edges;
int p[MAXN];

void
initialize() {
  for (int i = 0; i <= n; i++) p[i] = i;  
}

int
findd(int u) {
  if (p[u] == u) return u;
  return p[u] = findd(p[u]);  
}

void
join(int u, int v) {
  int a = findd(u);
  int b = findd(v);
  if (a == b) return;
  p[a] = b; 
}

double
kruskal() {
  initialize();
  sort(edges.begin(), edges.end());
  
  int times = 0;
  double ans = 0.0;
  for (int i = 0; i < edges.size() && times < n - s; i++) {
    int u = edges[i].a;
    int v = edges[i].b;
    double w = edges[i].w; 
    if (findd(u) != findd(v)) {
      ans = w;
      times++;
      join(u, v);
    }
  }
  return ans;
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> s >> n;
    edges.clear();
    points.clear();
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points.push_back(Point(x, y));
      for (int j = 0; j < i; j++) {
        edges.push_back(Edge(j, i, dist(points[j], points[i])));
      }
    }
    printf("%.2f\n", kruskal());
  }
  return 0;
}
