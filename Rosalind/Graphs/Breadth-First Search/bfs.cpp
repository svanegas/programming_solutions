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
int d[MAXN];
vector <int> g[MAXN];
int n, m;

void
bfs() {
  for (int i = 1; i <= n; i++) d[i] = -1;
  d[1] = 0;
  queue <int> q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];
      if (d[next] == -1) {
        d[next] = d[cur] + 1;
        q.push(next); 
      } 
    }
  }
}

int
main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  bfs();
  for (int i = 1; i <= n; i++) {
    cout << d[i];
    if (i == n) cout << endl;
    else cout << " "; 
  }
  return 0;
}
