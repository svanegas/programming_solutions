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

typedef long long ll;
const int MAXN = 100005;
int n;
ll house[MAXN];


int
main() {
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> house[i]; 
    }
    ll tot = 0LL;
    for (int i = 0; i < n; i++) {
      tot += abs(house[i]);
      house[i+1] += house[i]; 
    }
    cout << tot << endl;
  }
  return 0;
}
