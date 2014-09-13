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
const int MAXN = 20005;
ll dpI[MAXN], dpD[MAXN], nums[MAXN];
int n;

int
binarySearch(int low, int high, ll key) {
  int mid;
  while (high - low > 1 ) {
    mid = low + (high - low) / 2;
    (nums[mid] >= key ? high : low) = mid;
  }
  return high;
}

bool
lis() {
  dpI[0] = dpD[0] = nums[0];
  int pointerI = 1, pointerD = 1;
  
  memset(dpI, 0, sizeof(dpI[0]) * n);
  memset(dpD, 0, sizeof(dpD[0]) * n);
  for (int i = 1; i < n; i++) {
    /* LIS */
    if (nums[i] < dpI[0]) { 
      dpI[0] = nums[i];
    }
    else if (nums[i] > dpI[pointerI-1]) { 
      dpI[pointerI++] = nums[i];
    }
    else {
      int donde = binarySearch(-1, pointerI-1, nums[i]);
      dpI[donde] = nums[i];
    }
    /* LDS */
    if (nums[i] > dpD[0]) {
      dpD[0] = nums[i];
    }
    else if (nums[i] < dpD[pointerD-1]) { 
      dpD[pointerD++] = nums[i];
    }
    else {
      int donde = binarySearch(-1, pointerD-1, nums[i]);
      dpD[donde] = nums[i];
    }
  }
  return pointerI == pointerD;
}

int
main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      dpI[i] = dpD[i] = 0;
    } 
    if (lis()) puts("Caution. I will not intervene.");
    else puts("Don't worry. I must intervene.");
  }
  return 0;
}
