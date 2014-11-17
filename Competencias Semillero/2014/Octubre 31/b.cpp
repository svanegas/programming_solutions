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

typedef long long ll;
int n;
ll w, d, res;

int
main() {
  while (cin >> n >> w >> d >> res) {
    ll sum = 0LL;
    for (int i = 1; i < n; ++i) {
      sum += (i * w);
    }
    bool found = false;
    for (int i = 1; i < n && !found; ++i) {
      if (sum - (i * d) == res) {
        cout << i << endl;
        found = true;
      } 
    }
    if (!found) cout << n << endl;
  }
  return 0;
}
