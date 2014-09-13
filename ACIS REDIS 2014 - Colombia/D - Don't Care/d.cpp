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

const int MAXN = 1005;
int n, m;
vector <int> g[MAXN];
vector <int> gbid[MAXN];
int group[MAXN];
int sink[MAXN];
int color[MAXN];
enum {WHITE, GRAY, BLACK};

void
dfs(int u, int comp) {
  group[u] = comp;
  for (int i = 0; i < gbid[u].size(); i++) {
    int v = gbid[u][i];
    if (group[v] == -1) dfs(v, comp); 
  }  
}

bool
dfs2(int u) {
  color[u] = GRAY;
  if (!g[u].size()) {
    if (sink[group[u]] != -1) {
      if (sink[group[u]] != u) return false; //Distinct sink in same group
    }
    else sink[group[u]] = u;
  }
  bool ret = true;
  for (int i = 0; i < g[u].size() && ret; i++) {
    int v = g[u][i];
    if (color[v] == GRAY) return false; //Cycle
    else if (color[v] == WHITE) ret &= dfs2(v); 
  }
  color[u] = BLACK;
  return ret;
}

int
main() {
  while (cin >> n >> m && n) {
    for (int i = 0; i <= n; i++) {
       g[i].clear();
       gbid[i].clear();
       group[i] = -1;
       sink[i] = -1;
       color[i] = WHITE;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      gbid[a].push_back(b);
      gbid[b].push_back(a);
    }
    int comp = 0;
    for (int i = 0; i < n; i++) {
      if (group[i] == -1) dfs(i, comp++);
    }
    bool can = true;
    for (int i = 0; i < n && can; i++) {
      if (color[i] == WHITE) {
        can &= dfs2(i);
      }
    }
    if (can) cout << "1" << endl;
    else cout << "0" << endl;
  }
  return 0;
}
