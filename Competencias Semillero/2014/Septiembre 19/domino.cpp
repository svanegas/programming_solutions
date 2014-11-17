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

const int MAXN = 100005;
int t, n, m;
vector <int> g[MAXN], sg[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort, super_topo;
set <int> dom[MAXN];
int scc[MAXN];
bool seen[MAXN], super_seen[MAXN];

void
dfs1(int u) {
  seen[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (!seen[v]) dfs1(v); 
  }  
  topo_sort.push_back(u);
}

void
dfs2(int u, int comp) {
  scc[u] = comp;
  for (int i = 0; i < grev[u].size(); i++) {
    int v = grev[u][i];
    if (scc[v] == -1) dfs2(v, comp); 
  }  
}

int
find_scc() {
  for (int u = 0; u < n; ++u) {
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i];
      grev[v].push_back(u);
    }
  }  
  for (int i = 0; i < n; ++i) {
    if (!seen[i]) dfs1(i); 
  }
  reverse(topo_sort.begin(), topo_sort.end());
  int comp = 0;
  for (int i = 0; i < n; ++i) {
    int u = topo_sort[i];
    if (scc[u] == -1) dfs2(u, comp++); 
  }
  return comp;
}

void
build_super_graph() {
  for (int i = 0; i < n; i++) {
    int compI = scc[i];
    for (int j = 0; j < g[i].size(); j++) {
      int compJ = scc[g[i][j]];
      if (compI != compJ) {
        sg[compI].push_back(compJ);
      }
    } 
  }
}

void
super_dfs(int u) {
  super_seen[u] = true;
  for (int i = 0; i < sg[u].size(); ++i) {
    int v = sg[u][i];
    if (!super_seen[v]) super_dfs(v); 
  }  
  super_topo.push_back(u);
}

void
build_super_topo(int comps) {
  for (int i = 0; i < comps; ++i) {
    if (!super_seen[i]) super_dfs(i); 
  }
  reverse(super_topo.begin(), super_topo.end());
}

void
solve(int u) {
  super_seen[u] = true; 
  for (int i = 0; i < sg[u].size(); ++i) {
    int v = sg[u][i];
    if (!super_seen[v]) solve(v); 
  }
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    topo_sort.clear();
    super_topo.clear();
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      sg[i].clear();
      grev[i].clear();
      dom[i].clear(); 
      seen[i] = super_seen[i] = false;
      scc[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
    } 
    int comps = find_scc();
    build_super_graph();
    
    build_super_topo(comps);
    
    int ans = 0;
    for (int i = 0; i <= comps; ++i) super_seen[i] = false;
    for (int i = 0; i < comps; ++i) {
      if (!super_seen[i]) {
        solve(i);
        ans++; 
      } 
    }
    cout << ans << endl;
  }
  return 0;
}
