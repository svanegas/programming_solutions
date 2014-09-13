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

const int MAXN = 30005;
vector <int> g[MAXN];
bool visit[MAXN];
int n, m;

void
dfs(int s) {
  visit[s] = true;
  for (int i = 0; i < g[s].size(); i++) {
    if (!visit[g[s][i]]) dfs(g[s][i]);
  }
  cout << s << " ";
}

int
main() {
  memset(visit, false, sizeof visit);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b); 
  }
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) dfs(i); 
  }
  return 0;
}
