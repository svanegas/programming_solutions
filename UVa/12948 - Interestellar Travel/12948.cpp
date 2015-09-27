// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct edge {
  int to;
  ll c, t;
  edge() {}
  edge(int _to, ll _c, ll _t) : to(_to), c(_c), t(_t) { }
};

const ll INF = 1LL << 50;
const int MAXN = 305;
const int STOPS = 302;
const int MAXS = 35;
map <string, int> id;
vector <edge> g[MAXN];
ll cost[MAXN][MAXN], dur[MAXN][MAXN];
int n, m, q;

void
bellman_ford(int src) {
  for (int i = 0; i <= n; ++i) {
    cost[0][i] = INF;
    dur[0][i] = INF;
  }
  cost[0][src] = dur[0][src] = 0LL;
  int edges = STOPS + 1;
  for (int k = 1; k <= edges; ++k) {
    for (int i = 0; i < n; ++i) {
      cost[k][i] = cost[k - 1][i];
      dur[k][i] = dur[k - 1][i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        edge next = g[i][j];
        int v = next.to;
        ll c = next.c;
        ll t = next.t;
        if (cost[k - 1][i] + c < cost[k][v]) {
          cost[k][v] = cost[k - 1][i] + c;
          dur[k][v] = dur[k - 1][i] + t;
        }
        else if (cost[k - 1][i] + c == cost[k][v]) {
          dur[k][v] = min(dur[k][v], dur[k][i] + t);
        }
      }
    }
  }
}

void
clean() {
  for (int i = 0; i <= n; ++i) {
    g[i].clear(); 
  }
  id.clear();
}

int
main() {
  bool first = true;
  while (scanf("%d %d %d", &n, &m, &q) != EOF) {
    if (!first) puts(".");
    first = false;
    clean();
    for (int i = 0; i < n; ++i) {
      char p_name[MAXS];
      scanf("%s", p_name);
      string name(p_name);
      id[name] = i;
    }
    char p_src[MAXS], p_dest[MAXS];
    for (int i = 0; i < m; ++i) {
      ll c, t;
      scanf("%s %s %lld %lld", p_src, p_dest, &c, &t);
      string src(p_src), dest(p_dest);
      if (src == dest) continue;
      int s_id = id[src], d_id = id[dest];
      g[s_id].push_back(edge(d_id, c, t));
    }
    int src;
    scanf("%s", p_src);
    string s_name(p_src);
    src = id[s_name];
    bellman_ford(src);
    for (int i = 0; i < q; ++i) {
      int stops, dst;
      scanf("%s %d", p_dest, &stops);
      string dest(p_dest);
      dst = id[dest];
      int edges = min(stops + 1, n - 1);
      if (cost[edges][dst] == INF) printf("* *\n");
      else printf("%lld %lld\n", cost[edges][dst], dur[edges][dst]);
    }
  }
  return 0;
}

