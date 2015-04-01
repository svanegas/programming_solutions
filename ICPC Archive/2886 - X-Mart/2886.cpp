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

const int MAXN = 20005;
int c, p, x, y, s, t, ticks, next_comp;
vector <int> g[MAXN];
int disc[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack <int> st;

inline int no(int a) { return -1 * a; }
inline int index(int i) { if (i > 0) return i; else return p - i; }

void
clean() {
  while (!st.empty()) st.pop();
  for (int i = 0; i <= p; ++i) {
    g[index(i)].clear();
    disc[index(i)] = low[index(i)] = scc[index(i)] = -1;
    stacked[index(i)] = false;
    g[index(no(i))].clear();
    disc[index(no(i))] = low[index(no(i))] = scc[index(no(i))] = -1;
    stacked[index(no(i))] = false;
  }
  ticks = next_comp = 0;
}

/* Makes edges corresponding to the expression a v b
   i.e. ~a -> b and ~b -> a */
void
make_avb(int a, int b) { 
  g[index(no(a))].push_back(index(b));
  g[index(no(b))].push_back(index(a));
}

void
build_graph() {
  for (int i = 0; i < c; ++i) {
    cin >> x >> y;
    if (x != 0 || y != 0) {
      if (!x || !y) make_avb(x | y, x | y);
      else make_avb(x, y);
    }
    cin >> s >> t;
    if (s != 0 || t != 0) {
      if (!s || !t) make_avb(no(s | t), no(s | t));
      else make_avb(no(s), no(t));
    }
  }
}

void
tarjan(int u) {
  disc[u] = low[u] = ticks++;
  st.push(u);
  stacked[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int next = g[u][i];
    if (disc[next] == -1) {
      tarjan(next);
      low[u] = min(low[u], low[next]);
    }
    else if (stacked[next]) low[u] = min(low[u], low[next]);
  }
  if (disc[u] == low[u]) {
    int next;
    do {
      next = st.top();
      st.pop();
      stacked[next] = false;
      scc[next] = next_comp;
    }
    while (u != next);
    next_comp++;
  }
}

bool
two_sat() {
  for (int i = 1; i <= p; ++i) {
    if (scc[index(i)] == scc[index(no(i))]) return false;
  }
  return true;
}

int
main() {
  while (cin >> c >> p && c && p) {
    clean();
    build_graph();
    for (int i = 1; i <= p; ++i) {
      if (scc[index(i)] == -1) {
        tarjan(index(i));
      }
      if (scc[index(no(i))] == -1) {
        tarjan(index(no(i)));
      }
    }
    if (two_sat()) puts("yes");
    else puts("no");
    
  }  
  return 0;
}
