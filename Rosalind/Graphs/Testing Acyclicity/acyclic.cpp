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

const int MAXN = 1003;
int t, n, m;
vector <int> g[MAXN];
enum COLOR {WHITE, GRAY, BLACK};
int color[MAXN];

bool
dfs(int s) {
  bool ret = true;
  color[s] = GRAY;
  for (int i = 0; i < g[s].size(); i++) {
    int next = g[s][i];
    if (color[next] == GRAY) return false;
    else if (color[next] == WHITE) {
      ret &= dfs(next);
    }
  }
  color[s] = BLACK;
  return ret;
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
      color[i] = WHITE;
      g[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b); 
    }
    bool acyclic = true;
    for (int i = 1; i <= n && acyclic; i++) {
      if (color[i] == WHITE) acyclic = dfs(i);
    }
    if (acyclic) cout << "1";
    else cout << "-1";
    if (t) cout << " ";
    else cout << endl;
  }
  return 0;
}
