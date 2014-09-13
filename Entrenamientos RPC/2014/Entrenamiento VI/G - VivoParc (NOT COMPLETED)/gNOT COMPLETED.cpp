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

const int MAXN = 105;
int n;
set <int> g[MAXN];
int color[MAXN];

bool
dfs(int s) {
  for (int i = 1; i <= 4; i++) {
    bool can = true;
    set <int> :: iterator it;
    for (it = g[s].begin(); it != g[s].end(); it++) {
      int next = *it;
      if (color[next] == i) {
        can = false;
        break;
      }
    }
    if (can) {
      color[s] = i;
      if (s == n) return true;
      return dfs(s + 1); 
    } 
  }
  return false;
}

int
main() {
  cin >> n;
  int a, b;
  while (scanf("%d-%d", &a, &b) != EOF) {
    g[a].insert(b);
    if (a != b) g[b].insert(a);
  }
  for (int i = 0; i <= n; i++) color[i] = -1;
  bool colorable = true;
  if (dfs(0)) {
    for (int i = 1; i <= n; i++) {
      cout << i << " " << color[i] << endl; 
    } 
  }
  else puts("No");
  return 0;
}
