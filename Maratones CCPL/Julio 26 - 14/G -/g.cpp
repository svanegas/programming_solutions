using namespace std;

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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define PI acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 2005;
int n, m;
vector <int> g[MAXN];
int d[MAXN];

bool
bfs(int s) {
  int cont = 1;
  for (int i = 0; i <= n; i++) d[i] = -1;
  queue <int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];
      if (d[next] == -1) {
        cont++;
        d[next] = 1;
        q.push(next);
      }
    }
  }
  return cont == n;
}

int
main() {
  while (cin >> n >> m && n && m) {
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 0; i < m; i++) {
      int v, w, p;
      cin >> v >> w >> p;
      v--; w--;
      if (p == 1) g[v].push_back(w);
      else {
        g[v].push_back(w);
        g[w].push_back(v);
      }
    }

    bool puede = true;
    for (int i = 0; i < n; i++) {
      if (!bfs(i)) {
        puede = false;
        break;
      }
    }
    if (puede) cout << "1" << endl;
    else cout << "0" << endl;
  }
  return 0;
}
