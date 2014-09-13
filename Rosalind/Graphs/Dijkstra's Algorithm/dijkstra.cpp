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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef pair <int, int> node;
typedef pair <int, int> dist_node;
const int MAXN = 1003;
const int INF = 1 << 30;
vector <node> g[MAXN];
priority_queue <dist_node,
                vector <dist_node>,
                greater<dist_node> > q;
int d[MAXN];
int n, m;

void
dijkstra(int s) {
  d[s] = 0;
  q.push(dist_node(d[s], s));
  while (!q.empty()) {
    int cur = q.top().second;
    int dist = q.top().first;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i].first;
      int weight = g[cur][i].second;
      if (d[next] > d[cur] + weight) {
        d[next] = d[cur] + weight;
        q.push(dist_node(d[next], next)); 
      }
    } 
  }
}

int
main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) d[i] = INF;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(node(b, w)); 
  }
  dijkstra(1);
  cout << d[1];
  for (int i = 2; i <= n; i++) cout << " " << (d[i] == INF ? -1 : d[i]);
  cout << endl;
  return 0;
}
