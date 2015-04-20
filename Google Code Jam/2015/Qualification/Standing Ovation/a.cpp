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

int t, n, clapping, ans, z = 1;
string s;

int
main() {
  cin >> t;
  while (t--) {
    clapping = ans = 0;
    cin >> n >> s;
    clapping += toInt(s[0]);
    for (int i = 1; i <= n; ++i) {
      int required = toInt(i);
      if (clapping < required) {
        ans += required - clapping;
        clapping += (required - clapping);
      }
      clapping += toInt(s[i]);
    }
    printf("Case #%d: %d\n", z++, ans);
  }
  return 0;
}
