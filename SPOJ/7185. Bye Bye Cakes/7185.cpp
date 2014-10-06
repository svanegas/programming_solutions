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

const int MAXN = 5;
int have[MAXN], req[MAXN];
int n = 4;

int
main() {
  while (cin >> have[0] && have[0] != -1) {
    for (int i = 1; i < n; ++i) cin >> have[i];
    for (int i = 0; i < n; ++i) cin >> req[i];
    int obj = -1;
    for (int i = 0; i < n; ++i) {
      int makes = have[i] / req[i];
      makes += (have[i] % req[i] != 0);
      if (makes > obj) obj = makes; 
    }
    for (int i = 0; i < n; ++i) {
      int needs = req[i] * obj;
      cout << needs - have[i];
      if (i == n - 1) cout << endl;
      else cout << " "; 
    }
  }
  return 0;
}
