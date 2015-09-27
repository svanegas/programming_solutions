// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
  int a, b;
  ll w;
  edge() {}
  edge(int _a, int _b, ll _w) : a(_a), b(_b), w(_w) {}
  bool operator < (const edge &than) const {
    return w < than.w;
  }
  bool operator > (const edge &than) const {
    return w > than.w; 
  }
};

const int MAXN = 405;
int n, m;
map <string, int> ind;
priority_queue <edge, vector <edge>, greater <edge> > edges;
int p[MAXN];

int
find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);  
}

void
join(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return;
  p[a] = b; 
}

ll
kruskal() {
  ll total = 0LL;
  int used = 0;
  while (!edges.empty() && used < n - 1) {
    edge cand = edges.top(); edges.pop();
    int u = cand.a;
    int v = cand.b;
    ll w = cand.w;
    if (find(u) != find(v)) {
      total += w;
      join(u, v);
      used++; 
    }
  }
  if (used == n - 1) return total;
  else return -1LL;
}

int
main() {
  while (cin >> n >> m && n) {
    for (int i = 0; i <= n; ++i) p[i] = i;
    edges = priority_queue <edge, vector <edge>, greater <edge> >();
    ind.clear();
    for (int i = 0; i < n; ++i) {
      string city; cin >> city;
      ind[city] = i;
    }
    for (int i = 0; i < m; ++i) {
      string a, b;
      ll w;
      cin >> a >> b >> w;
      edges.push(edge(ind[a], ind[b], w));
    }
    string trash; cin >> trash;
    ll ans = kruskal();
    if (ans != -1LL) cout << ans << endl;
    else cout << "Impossible" << endl;
  }
  return 0;
}

