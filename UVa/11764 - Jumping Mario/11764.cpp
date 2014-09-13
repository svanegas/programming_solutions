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

int t, n, low, high, act;

int
main() {
  cin >> t;
  for (int c = 1; c <= t; c++) {
    low = high = 0;
    cin >> n; 
    cin >> act;
    for (int i = 1; i < n; i++) {
      int xi; cin >> xi;
      if (xi > act) high++;
      if (xi < act) low++;
      act = xi;
    }
    printf("Case %d: %d %d\n", c, high, low);
  }
  return 0;
}
