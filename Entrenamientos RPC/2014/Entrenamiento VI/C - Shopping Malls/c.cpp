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

struct place {
  int floor, x, y;
  place (int Floor, int X, int Y) : floor(Floor), x(X), y(Y) {}  
};

inline int distsqr(const place &a, const place &b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const place &a, const place &b) {
  return sqrt(distsqr(a, b));  
}

typedef pair<double, int> edge;
const int MAXN = 205;
const int INF = 1 << 30;
int n, m, q;
vector <edge> g[MAXN];
vector <place> places;
double d[MAXN];
int p[MAXN];

void
dijkstra(int s) {
  for (int i = 0; i <= n; i++) {
    d[i] = INF * 1.0; 
    p[i] = -1;
  }
  priority_queue <edge, vector <edge>, greater <edge> > q;
  d[s] = 0.0;
  q.push(edge(0.0, s));
  while (!q.empty()) {
    double dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i].second;
      double w_extra = g[cur][i].first;
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        p[next] = cur;
        q.push(edge(d[next], next)); 
      } 
    } 
  }
}

vector <int>
find_path(int t) {
  vector <int> path;
  int cur = t;
  while (cur != -1) {
    path.push_back(cur);
    cur = p[cur]; 
  }  
  reverse(path.begin(), path.end());
  return path;
}

int
main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int floor, x, y;
    cin >> floor >> x >>  y;
    places.push_back(place(floor, x, y));
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    string way;
    cin >> a >> b >> way;
    if (way == "walking") {
      double w = dist(places[a], places[b]);
      g[a].push_back(edge(w, b));
      g[b].push_back(edge(w, a));
    }
    else if (way == "stairs") {
      double w = dist(places[a], places[b]);
      w = hypot(w, 5.0 * abs(places[a].floor - places[b].floor));
      g[a].push_back(edge(w, b));
      g[b].push_back(edge(w, a));
    }
    else if (way == "lift") {
      g[a].push_back(edge(1.0, b));
      g[b].push_back(edge(1.0, a)); 
    }
    else if (way == "escalator") {
      g[a].push_back(edge(1.0, b));
      double w = dist(places[b], places[a]);
      w = hypot(w, 5.0 * abs(places[a].floor - places[b].floor)); 
      g[b].push_back(edge(w * 3.0, a));
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    dijkstra(a);
    vector <int> path = find_path(b);
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
      cout << " " << path[i]; 
    }
    cout << endl;
  }
  return 0;
}
