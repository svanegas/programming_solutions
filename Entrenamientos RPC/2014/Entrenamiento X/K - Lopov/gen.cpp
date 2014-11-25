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
  int n = 300000, k = 300000;
  cout << n << " " << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << (1 + rand() % 1000000) << " " << (1 + rand() % 1000000) << endl;
  }
  for (int i = 0; i < k; ++i) {
    cout << (1 + rand() % 100000000) << endl;
  }
  return 0;
}
