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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct city {
  double lat, lon;
  string name;
  city (string N, double Lat, double Lon) : lat(Lat), lon(Lon), name(N) {}
};

struct Vector3D {
  double x, y, z;
  Vector3D (double X, double Y, double Z) : x(X), y(Y), z(Z) {}  
   
  double dot(const Vector3D &b) {
    return x * b.x + y * b.y + z * b.z;
  }
};

typedef long long ll;
const int MAXN = 105;
const ll INF = 1LL << 60;
typedef pair <ll, int> dist_node;
typedef pair <int, ll> edge;
int n, m, q;
vector <city> cities;
map <string, int> ind;
vector <edge> g[MAXN];
ll d[MAXN];
double R = 6378.0, C = 2 * PI * R;

double
toRad(double deg) {
  return deg * PI / 180;  
}
 
double
toDeg(double rad) {
  return rad * 180 / PI;
}

void
dijkstra(int s) {
  for (int i = 0; i <= n; ++i) d[i] = INF;
  priority_queue <dist_node, vector <dist_node>, greater<dist_node> > q;
  d[s] = 0LL;
  q.push(dist_node(0, s));
  while (!q.empty()) {
    int dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i].first;
      int w_extra = g[cur][i].second;
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        q.push(dist_node(d[next], next));
      }
    }
  }
}

ll
dist(int a, int b) {
  double lat1 = cities[a].lat, lat2 = cities[b].lat;
  double lon1 = cities[a].lon, lon2 = cities[b].lon;
  lat1 = toRad(lat1); lon1 = toRad(lon1);
  lat2 = toRad(lat2); lon2 = toRad(lon2);
  Vector3D v1 = Vector3D(cos(lat1) * cos(lon1),
                         cos(lat1) * sin(lon1),
                         sin(lat1));
  Vector3D v2 = Vector3D(cos(lat2) * cos(lon2),
                         cos(lat2) * sin(lon2),
                         sin(lat2));
  double AdotB = v1.dot(v2);
  double angle = acos(AdotB);
  double arc = toDeg(angle) / 360.0 * C;
  return ((ll) round(arc));
}

int main() {
  int z = 1;
  while (cin >> n >> m >> q && n) {
    if (z != 1) cout << endl;
    cities.clear();
    ind.clear();
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      string name;
      double lat, lon;
      cin >> name >> lat >> lon;
      cities.push_back(city(name, lat, lon));
      ind[name] = i;
    }
    for (int i = 0; i < m; ++i) {
      string n1, n2;
      cin >> n1 >> n2;
      ll w = dist(ind[n1], ind[n2]);
      g[ind[n1]].push_back(edge(ind[n2], w));
    }
    printf("Case #%d\n", z++);
    for (int i = 0; i < q; ++i) {
      string a, b;
      cin >> a >> b;
      dijkstra(ind[a]);
      ll ans = d[ind[b]];
      if (ans >= INF) cout << "no route exists" << endl;
      else cout << ans << " km" << endl;
    }
  }
  return 0; 
}
