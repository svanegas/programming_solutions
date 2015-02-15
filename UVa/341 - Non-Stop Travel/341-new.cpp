#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 12;
typedef pair <int, int> edge; //<weight, to>
int n, m, src, dest, z;
vector <edge> g[MAXN];
int d[MAXN], p[MAXN];

void
dijkstra() {
  for (int i = 0; i <= n; ++i) {
    d[i] = INF; p[i] = -1;
  }
  priority_queue <edge, vector <edge>, greater <edge> > q;
  d[src] = 0;
  q.push(edge(0, src));
  while (!q.empty()) {
    int dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i].second;
      int w_extra = g[cur][i].first;
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        p[next] = cur;
        q.push(edge(d[next], next));
      }
    }
  }
}

vector <int>
find_path() {
  vector <int> path;
  int cur = dest;
  while (cur != -1) {
    path.push_back(cur);
    cur = p[cur];
  }
  reverse(path.begin(), path.end());
  return path;
}

int
main() {
  z = 1;
  while (cin >> n && n) {
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      cin >> m;
      int b, w;
      for (int j = 0; j < m; ++j) {
        cin >> b >> w;
        g[i].push_back(edge(w, b));
      }
    }
    cin >> src >> dest;
    dijkstra();
    cout << "Case " << (z++) << ": Path =";
    vector <int> path = find_path();
    for (int i = 0; i < path.size(); ++i) {
      cout << " " << path[i];
    }
    cout << "; " << d[dest] << " second delay" << endl;
  }
  return 0;
}
