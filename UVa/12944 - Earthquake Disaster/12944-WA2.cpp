// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (1LL << 60) / 4LL;
const int MAXN = 525;
ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
int found[MAXN];
ll dist[MAXN], pi[MAXN], width[MAXN];
pair <int, int> dad[MAXN];

void
connect(int from, int to, ll ca, ll co) {
  cap[from][to] = ca;
  cost[from][to] = co;  
}

void
relax(int s, int k, ll ca, ll co, int dir) {
  ll val = dist[s] + pi[s] - pi[k] + co;
  if (ca && val < dist[k]) {
    dist[k] = val;
    dad[k] = make_pair(s, dir);
    width[k] = min(ca, width[s]); 
  }
}

ll
dijkstra(int s, int t, int n) {
  for (int i = 0; i <= n; ++i) {
    found[i] = false;
    dist[i] = INF;
    width[i] = pi[i] = 0LL;
  }
  dist[s] = 0LL;
  width[s] = INF;
  while (s != -1) {
    int best = -1;
    found[s] = true;
    for (int k = 0; k < n; ++k) {
      if (found[k]) continue;
      relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
      relax(s, k, flow[k][s], -cost[k][s], -1);
      if (best == -1 || dist[k] < dist[best]) best = k;
    }
    s = best;
  }
  for (int k = 0; k < n; ++k) pi[k] = min(pi[k] + dist[k], INF); 
  return width[t];
}

pair <ll, ll>
max_flow(int s, int t, int n) {
  ll totflow = 0, totcost = 0;
  while (ll amt = dijkstra(s, t, n)) {
    totflow += amt;
    for (int x = t; x != s; x = dad[x].first) {
      if (dad[x].second == 1) {
        flow[dad[x].first][x] += amt;
        totcost += amt * cost[dad[x].first][x];
      }
      else {
        flow[x][dad[x].first] -= amt;
        totcost -= amt * cost[x][dad[x].first]; 
      }
    }
  }
  return make_pair(totflow, totcost);
}

int
main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i <= n + m + 2; ++i) {
      found[i] = false;
      dist[i] = 0LL;
      pi[i] = 0LL;
      width[i] = 0LL;
      dad[i] = make_pair(0, 0);
      for (int j = 0; j <= n + m + 2; ++j) {
        cap[i][j] = flow[i][j] = cost[i][j] = 0LL;
      }
    }
    int source = n + m;
    for (int i = 0; i < n - 1; ++i) {
      ll ti; scanf("%lld", &ti);
      connect(source, i, ti, 0);
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      ll w, pr;
      scanf("%d %d %lld %lld", &a, &b, &w, &pr);
      a--; b--;
      connect(a, n + i, INF, pr);
      connect(n + i, a, INF, pr);
      connect(n + i, b, w, 0);
      connect(b, n + i, w, 0);
    }
    pair <ll, ll> ans = max_flow(source, n - 1, m + n + 1);
    printf("%lld %lld\n", ans.first, ans.second);
  }
  return 0; 
}
