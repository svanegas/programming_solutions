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

const int MAXN = 1005;
vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
int scc[MAXN];
bool seen[MAXN];
int n, m;

void
dfs1(int u) {
  seen[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
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
  for (int i = 0; i < n; i++) {
    seen[i] = false;
    scc[i] = -1;
    for (int j = 0; j < g[i].size(); j++) {
      int v = g[i][j];
      grev[v].push_back(i); 
    } 
  } 
  for (int i = 0; i < n; i++) {
    if (!seen[i]) dfs1(i); 
  } 
  reverse(topo_sort.begin(), topo_sort.end());
  
  int comp = 0;
  for (int i = 0; i < n; i++) {
    int u = topo_sort[i];
    if (scc[u] == -1) dfs2(u, comp++); 
  }
  return comp;
}

int
main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << find_scc() << endl;
  return 0;
}
