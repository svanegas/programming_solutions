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

//157.253.238.31
//team608
//539207a2

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

double d, v;

int
main() {
  while (cin >> d >> v && (d || v)) {
    printf("%.3f\n", (pow(pow(d, 3.0) - ((6.0 * v)/M_PI), 1.0/3.0)) + EPS);
  }
  return 0;
}
