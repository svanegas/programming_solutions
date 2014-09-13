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
const int MAXN = 10005;
int t, n;
ll dpI[MAXN], dpD[MAXN], w[MAXN], h[MAXN];
ll maxiD, maxiI;

void
lis() {
  dpI[0] = w[0];
  dpD[0] = w[0];
  for (int i = 1; i < n; i++) {
    dpI[i] = w[i];
    dpD[i] = w[i];
    for (int j = 0; j < i; j++) {
      if (h[j] < h[i]) {
        dpI[i] = max(dpI[i], dpI[j] + w[i]); 
      }
      if (h[j] > h[i]) {
        dpD[i] = max(dpD[i], dpD[j] + w[i]); 
      }
    } 
  }
  maxiD = maxiI = 0LL;
  for (int i = 0; i < n; i++) {
    maxiD = max(maxiD, dpD[i]);
    maxiI = max(maxiI, dpI[i]);
  }
}

int
main() {
  cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    lis();
    printf("Case %d. ", c);
    if (maxiI >= maxiD) {
      printf("Increasing (%lld). Decreasing (%lld).\n", maxiI, maxiD);
    }
    else {
       printf("Decreasing (%lld). Increasing (%lld).\n", maxiD, maxiI);
    }
  }
  return 0;
}
