#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
  int start, end, weight;

  edge(int u, int v, int w) {
    start = u; end = v; weight = w;
  }

  bool operator < (const edge &other) const {
    return weight < other.weight;
  }
};

const int MAXN = 505;
vector <edge> edges;
vector <string> keys;
int p[MAXN];

void initialize(int n) {
  for (int i = 0; i <= n; ++i) p[i] = i;
}

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void join(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return;
  p[a] = b;
}

int kruskal(int n) {
  initialize(n);
  sort(edges.begin(), edges.end());

  int total = 0;
  for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i].start;
    int v = edges[i].end;
    int w = edges[i].weight;
    if (find(u) != find(v)) {
      total += w;
      join(u, v);
    }
  }
  return total;
}

int dist(string a, string b) {
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    int c1 = a[i] - '0';
    int c2 = b[i] - '0';
    int ma = max(c1, c2);
    int me = min(c1, c2);
    ans += min(ma - me, me + 10 - ma);
  }
  return ans;
}

int
main() {
  int t; cin >> t;
  while (t--) {
    edges.clear();
    keys.clear();
    int n; cin >> n;
    bool isKey = false;
    for (int i = 0; i < n; ++i) {
      string key; cin >> key;
      isKey |= (key == "0000");
      keys.push_back(key);
      for (int j = 0; j < i; ++j) {
        int w = dist(keys[j], key);
        edges.push_back(edge(j, i, w));
      }
    }
    int ans = kruskal(n);
    int mini = 10 * 4;
    for (int i = 0; i < n; ++i) {
      mini = min(mini, dist(keys[i], "0000"));
    }
    ans += isKey ? 0 : mini;
    cout << ans << endl;
  }
  return 0;
}
