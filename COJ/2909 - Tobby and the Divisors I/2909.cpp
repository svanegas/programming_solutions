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

int t, n;

int
main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0, maxi = 0;
    for (int i = 1; i <= n; i++) {
      int div = 0;
      for (int j = 1; j <= i; j++) {
        div += !(i % j);
      }
      if (div > maxi) {
        maxi = div;
        ans = i; 
      }
    }
    cout << ans << endl;
  }
  return 0;
}
