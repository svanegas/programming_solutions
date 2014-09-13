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

int t;
int dogs[6];

bool
can(int mask, int boat1, int boat2) {
  if (mask == (1 << 6) - 1) return boat1 == boat2;
  int i;
  for (i = 0; i < 6; i++) if (!(mask & (1 << i))) break; 
  int next = dogs[i];
  return can(mask | (1 << i), boat1 + next, boat2) |
         can(mask | (1 << i), boat1, boat2 + next);
}

int
main() {
  cin >> t;
  while (t--) {
    for (int i = 0; i < 6; i++) cin >> dogs[i];
    if (can(0, 0, 0)) puts("Tobby puede cruzar");
    else puts("Tobby no puede cruzar");
  }
  return 0;
}
