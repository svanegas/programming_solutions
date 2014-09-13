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

int n, d;

int
main() {
  cin >> n >> d;
  int elapsed = 0;
  int jokes = 0;
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    elapsed += xi;
    if (i < n - 1) {
      elapsed += 10;
      jokes += 2;
    }
    else {
      jokes += ((d - elapsed) / 5);
    }
  }
  if (elapsed > d) cout << "-1" << endl;
  else cout << jokes << endl;
  return 0;
}
