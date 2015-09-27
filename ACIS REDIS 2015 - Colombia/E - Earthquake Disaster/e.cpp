// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef vector <int> VI;
typedef vector <VI> VII;
typedef long long L;
typedef vector <L> VL;
typedef vector <VL> VVL;
typedef pair <int, int> PII;
typedef vector <PII> VPII;

const L INF = numeric_limits <L> :: max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;
  MinCostMaxFlow(int N) : N(N),
  cap(N, VL(N)),
  flow(N, VL(N)),
  cost(N, VL(N)),
  found(N),
  dist(N),
  pi(N),
  width(N),
  dad(N) {}
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }
  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; ++k) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }
    for (int k = 0; k < N; ++k) {
      pi[k] = min(pi[k] + dist[k], INF);
    }
    return width[t];
  }
  pair <L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
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
};

int
main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    int N = n + m + 1;
    MinCostMaxFlow ans(N);
    int source = n + m;
    for (int i = 0; i < n - 1; ++i) {
      L ti; scanf("%lld", &ti);
      ans.AddEdge(source, i, ti, 0LL);
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      L w, pr;
      scanf("%d %d %lld %lld", &a, &b, &w, &pr);
      a--; b--;
      ans.AddEdge(a, n + i, INF, pr);
      ans.AddEdge(n + i, a, INF, pr);
      ans.AddEdge(n + i, b, w, 0);
      ans.AddEdge(b, n + i, w, 0);
    }
    pair <L, L> resp = ans.GetMaxFlow(source, n - 1);
    printf("%lld %lld\n", resp.first, resp.second);
  }
  return 0;
}
