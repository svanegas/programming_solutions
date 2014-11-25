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

typedef pair <int, int> comb;
typedef long long ll;
const int MAXN = 10005;
const ll INF = 1LL << 62;
int n, m;
ll cost[MAXN];
bool seen[MAXN];
vector <comb> crafts[MAXN];

ll
solve() {
  for (int k = 0; k < n; ++k) {
    int ind = -1;
    ll localMin = INF;
    for (int i = 1; i <= n; ++i) {
      if (!seen[i] && cost[i] < localMin) {
        localMin = cost[i];
        ind = i; 
      }
    }
    seen[ind] = true;
    for (int j = 0; j < crafts[ind].size(); ++j) {
      comb mix = crafts[ind][j];
      int item2 = mix.second;
      cost[mix.first] = min(cost[mix.first], cost[ind] + cost[item2]);
    }
  }
  printf("%lld\n", cost[1]);
}

int
main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &cost[i]);
    seen[i] = false;
  }
  for (int i = 0; i < m; ++i) {
    int a, x, y;
    scanf("%d %d %d", &a, &x, &y);
    crafts[x].push_back(comb(a, y));
    crafts[y].push_back(comb(a, x));
  }
  solve();
  return 0;
}
