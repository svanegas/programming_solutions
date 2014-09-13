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
int color[MAXN];
int t, n, m;

bool
bfs(int s) {
  color[s] = 1;
  queue <int> q;
  q.push(s);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];
      if (color[next] == color[cur]) return false;
      else if (color[next] == -1) {
        color[next] = 1 - color[cur];
        q.push(next);
      } 
    } 
  }
  return true;
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      color[i] = -1;
      g[i].clear(); 
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bool bip = true;
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        if (!bfs(i)) {
          bip = false;
          break; 
        } 
      }
    }
    if (bip) cout << "1";
    else  cout << "-1";
    if (t) cout << " ";
    else cout << endl;
  }
  return 0;
}
