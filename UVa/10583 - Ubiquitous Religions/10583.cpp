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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 50005;
int n, m, z;
int p[MAXN];

void
initialize() {
  for (int i = 0; i <= n; i++) p[i] = i;
}

int
findd(int u) {
  if (p[u] == u) return u;
  return p[u] = findd(p[u]); 
}

void
join(int u, int v) {
  int a = findd(u);
  int b = findd(v);
  if (a == b) return;
  p[a] = b; 
}

int
main() {
  z = 1;
  while (cin >> n >> m && (n || m)) {
    initialize();
    for (int i = 0; i < m; i++) {
       int a, b;
       cin >> a >> b;
       a--; b--;
       join(a, b);
    }
    set <int> religions;
    for (int i = 0; i < n; i++) religions.insert(findd(i));
    printf("Case %d: %d\n", (z++), religions.size());
  }
  return 0;
}
