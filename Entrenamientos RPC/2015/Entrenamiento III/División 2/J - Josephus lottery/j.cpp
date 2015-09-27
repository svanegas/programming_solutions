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
int n, sz, k, way, del, cur;

int
main() {
  while (scanf("%d %d", &n, &k) && n) {
    list <int> players;
    list <int> :: iterator it;
    for (int i = 1; i <= n; ++i) players.push_back(i);
    way = 1, cur = 0;
    while (players.size() != 1) {
      sz = players.size();
      del = (sz + (cur + ((k-1) * way))) % sz;
      del = (sz + del) % sz;
      if (way == 1) {
        if (del == sz - 1) cur = 0;
        else cur = del;
      }
      else {
        if (del == 0) cur = sz - 2;
        else cur = del - 1;
      }
      it = players.begin();
      advance(it, del);
      players.erase(it);
      sz = players.size();
      if (way == 1) way = -1;
      else way = 1;
    }
    printf("%d\n", *players.begin());
  }
  return 0;
}

