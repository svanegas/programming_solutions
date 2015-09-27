// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, int> dist_node;
typedef pair <int, ll> edge;
const int INF = 1LL << 60;
const int MAXN = 10005;
vector <edge> g[MAXN];
int n, m, k;
ll d[MAXN];
vector <int> junc;
int sols = 0;

void dijkstra(int s) {
  for (int i = 0; i <= n; ++i) d[i] = INF;  
  priority_queue <dist_node, vector <dist_node>, greater <dist_node > > q;
  d[s] = 0LL;
  q.push(dist_node(0LL, s));
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
        if (next == junc[junc.size() - 1]) sols = 1;
      }
      else if (d[cur] + w_extra == d[next]) {
        d[next] = d[cur] + w_extra;
        q.push(dist_node(d[next], next));
        if (next == junc[junc.size() - 1]) sols++;
      }
    }
  }
}

int
main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int xi; cin >> xi;
    junc.push_back(xi);
  }
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(edge(b, w));
    g[b].push_back(edge(a, w));
  }
  dijkstra(junc[0]);
  printf("%s\n", sols > 1 ? "yes" : "no");
  return 0;
}

