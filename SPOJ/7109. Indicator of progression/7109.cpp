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

double n, m, prop;
int k, p;

int
main() {
  while (cin >> m >> n && m != -1.0) {
    prop = m / n;
    p = (int) round(prop * 100);
    k = (int) round(20.0 * prop);
    int i;
    for (i = 1; i <= min(k, 8); ++i) cout << "*"; 
    for ( ; i <= 8; ++i) cout << "-"; 
    if (p < 100) cout << (k > 8 ? "*" : "-");
    cout << p << "%";
    if (p < 10) cout << (k > 11 ? "*" : "-");
    for (i = 13; i <= k; ++i) cout << "*";
    for ( ; i <= 20; ++i) cout << "-";
    cout << endl;
  }
  return 0;
}
