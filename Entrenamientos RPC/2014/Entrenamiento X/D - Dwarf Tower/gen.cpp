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
#include <time.h>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int
main() {
  srand(time(NULL));
  int n = 10000, m = 100000;
  cout << n << " " << m << endl;
  for (int i = 0; i < n; ++i) {
    cout << rand() % 1000000001;
    if (i == n - 1) cout << endl;
    else cout << " ";
  }
  for (int i = 0; i < m; ++i) {
    int a, x, y;
    a = 1 + rand() % n;
    do {
      x = 1 + rand() % n;
    } while (x == a);
    do {
      y = 1 + rand() % n; 
    } while (y == a || y == x);
    cout << a << " " << x << " " << y << endl;
  }
  return 0;
}
