// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
const int MAXN = 10005;
typedef pair <int, int> edge;
vector <edge> g[MAXN];
ll d[2][MAXN];

void
dijkstra(int s, int ind, int n) {
  for (int i = 0; i <= n; ++i) d[ind][i] = INF;
  priority_queue <edge, vector <edge>, greater <edge> > q;
  d[ind][s] = 0LL;
  q.push(edge(0LL, s));
  while (!q.empty()) {
    ll dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[ind][cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i].second;
      ll w_extra = g[cur][i].first;
      if (d[ind][cur] + w_extra < d[ind][next]) {
        d[ind][next] = d[ind][cur] + w_extra;
        q.push(edge(d[ind][next], next));
      }
    }
  }
}

int
main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    g[a].push_back(edge(w, b));
    g[b].push_back(edge(w, a));
  }
  dijkstra(0, 0, n);
  dijkstra(n - 1, 1, n);
  ll ans = 0LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      int v = g[i][j].second;
      ll w = g[i][j].first;
      if (d[0][i] + d[1][v] + w == d[0][n-1]) ans += w;
    }
  }
  cout << ans * 2LL << endl;
  return 0;
}
