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

int
cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;  
}

double grams[3];
double tot;

int
main() {
  while (cin >> tot >> grams[0] >> grams[1] >> grams[2] &&
        (tot || grams[0] || grams[1] || grams[2])) {
    bool found = false;
    for (double i = -0.5; i <= 0.5 && !found; i += 0.1) {
      if (cmp(grams[0] + i, 0.0) == -1) continue;
      for (double j = -0.5; j <= 0.5 && !found; j += 0.1) { 
        if (cmp(grams[1] + j, 0.0) == -1) continue;
        for (double k = -0.5; k <= 0.5 && !found; k += 0.1) {
          if (cmp(grams[2] + k, 0.0) == -1) continue;
          double supI = grams[0] + i;
          double supJ = grams[1] + j;
          double supK = grams[2] + k;
          if (i == 0.5) i -= EPS;
          if (j == 0.5) j -= EPS;
          if (k == 0.5) k -= EPS;
          double supVal = supI * 9.0 + supJ * 4.0 + supK * 4.0;
          if (cmp(round(supVal), tot) == 0) found = true;
        }
      }
    }
    if (found) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
