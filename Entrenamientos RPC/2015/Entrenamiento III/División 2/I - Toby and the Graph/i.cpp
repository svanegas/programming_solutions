#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <limits>
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

const long double EPS = 1e-9;
const double PI = acos(-1.0);

int cmp(long double x, long double y = 0, long double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 10005;
int p[MAXN];
int t, n, m, ans;

void initialize(){
  for (int i = 0; i <= n; ++i) p[i] = i;
}

int find(int u){
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void join(int u, int v){
  int a = find(u);
  int b = find(v);
  if (a == b) return;
  p[a] = b;
}

int
main() {
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> m;
    initialize();
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      join(a, b);
    }
    set <int> diff;
    for (int i = 1; i <= n; ++i) {
      int x = find(i);
      diff.insert(x);
    }
    int conj = diff.size();
    for (int i = 0; i < conj; ++i) {
      for (int j = i + 1; j < conj; ++j) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}

