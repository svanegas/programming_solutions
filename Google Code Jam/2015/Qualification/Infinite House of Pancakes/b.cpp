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

const int INF = 9999;
int t, n, ans, special, maxi;
vector <int> dishes;

int
main() {
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    dishes.clear();
    cin >> n;
    ans = INF;
    special = 0;
    maxi = -1;
    for (int i = 0; i < n; ++i) {
      int pi; cin >> pi;
      dishes.push_back(pi);
      maxi = max(maxi, pi);
    }
    for (int i = 1; i <= maxi; ++i) {
      special = 0;
      for (int j = 0; j < n; ++j) {
        double parts = ceil(dishes[j] * 1.0 / i * 1.0);
        special += (int) (parts - 1.0);
      }
      ans = min(ans, special + i);
    }
    printf("Case #%d: %d\n", z, ans);
  }
  return 0;
}
