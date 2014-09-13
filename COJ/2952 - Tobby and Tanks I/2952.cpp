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
const int MAXN = 1005;
int n, q;
ll W[MAXN];
ll req[MAXN];

int
binarySearch(int low, int high, ll key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (req[mid] > key) high = mid;
     else low = mid + 1;
  }
  if (req[high] <= key) return high;
  else return high - 1;
}

void
build() {
  req[0] = 1;
  for (int i = 1; i < n; i++) req[i] = req[i-1] + W[i];    
}

int
main() {
  while (cin >> n >> q) {
    for (int i = 0; i < n; i++) cin >> W[i];
    build();
    for (int i = 0; i < q; i++) {
      ll qi; cin >> qi;
      cout << binarySearch(0, n - 1, qi) + 1;
      if (i == q - 1) cout << endl;
      else cout << " ";
    }
  }
  return 0;
}
