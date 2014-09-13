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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 1005;
int n;
int dpi[MAXN], dpd[MAXN];
int nums[MAXN];

int
solve() {
    int maxii = 1, maxid = 1;
    dpi[0] = dpd[0] = 1;
    for (int i = 1; i < n; i++) {
        dpi[i] = dpd[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j] && dpi[j] + 1 > dpi[i]) {
                dpi[i] = dpi[j] + 1;
                maxii = max(maxii, dpi[i]);
            }
            if (nums[i] < nums[j] && dpd[j] + 1 > dpd[i]) {
                dpd[i] = dpd[j] + 1;
                maxid = max(maxid, dpd[i]);
            }
        }   
    }
    if (maxii == maxid) puts("Caution. I will not intervene.");
    else puts("Don't worry. I must intervene.");
}

int
main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      int xi; cin >> xi;
      nums[i] = xi;
    }
    solve();
  }
  return 0;
}
