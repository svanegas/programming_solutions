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

int n, t1, t2, t3;

int
main() {
  while (cin >> n >> t1 >> t2 >> t3 && n) {
    int first = 2 * n;
    int second = n + (t2 - t1 + n) % n;
    int third = (t2 - t3 + n) % n;
    int tot = first + second + third;
    double ticks = n * (tot + (tot + n - 1)) / 2.0;
    printf("%.3f\n", ticks / n);
  }
  return 0;
}
