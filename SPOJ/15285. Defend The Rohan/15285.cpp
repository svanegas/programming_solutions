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

const int INF = 1 << 30;
const int MAXN = 55;
typedef pair <int, int> dist_node;
int t, n, r;
int w[MAXN][MAXN], d[MAXN];

int
dijkstra(int src, int dest) {
  for (int i = 0; i <= n; ++i) d[i] = INF;
  priority_queue <dist_node, vector <dist_node>, greater <dist_node> > q;
  d[src] = 0;
  q.push(dist_node(0, src));
  while (!q.empty()) {
    int dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 1; i <= n; ++i) {
      if (i == cur) continue;
      int next = i;
      int w_extra = w[cur][i];
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        q.push(dist_node(d[next], next)); 
      } 
    }
  }
  return d[dest];
}

int
main() {
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> w[i][j];
    cin >> r;
    int ans = 0;
    while (r--) {
      int a, b;
      cin >> a >> b;
      ans += dijkstra(a, b);
    }
    printf("Case #%d: %d\n", z, ans);
  }
  return 0;
}
