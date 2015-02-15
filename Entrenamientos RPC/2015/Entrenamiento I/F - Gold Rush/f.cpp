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

int t, n;
ll a, b;

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    ll mini = min(a, b);
    ll num = (1LL << n);
    int cont = 0;
    while (mini % num != 0) {
      cont++;
      num >>= 1;
    }
    cout << cont << endl;
  }
  return 0;
}

