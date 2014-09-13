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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n, cien, dos;
int
main() {
  cin >> n;
  while (n--) {
    int xi; cin >> xi;
    (xi == 100 ? cien : dos)++;
  }
  if (cien % 2 != 0) cout << "NO" << endl;
  else if (cien == 0 && dos % 2 == 1) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
