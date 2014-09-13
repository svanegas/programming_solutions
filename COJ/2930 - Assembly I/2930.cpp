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

const int MAXN = 1005;
int n;
int arr[MAXN], dpI[MAXN], dpD[MAXN];

bool
lis() {
  dpI[0] = dpD[0] = 1;
  for (int i = 1; i < n; i++) {
    dpI[i] = dpD[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[i] > arr[j]) dpI[i] = max(dpI[i], dpI[j] + 1);
      if (arr[i] < arr[j]) dpD[i] = max(dpD[i], dpD[j] + 1);
    }
  }
  int maxI = 0, maxD = 0;
  for (int i = 0; i < n; i++) {
    maxI = max(maxI, dpI[i]);
    maxD = max(maxD, dpD[i]);    
  }  
  return maxI == maxD;
}

int
main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (lis()) puts("Caution. I will not intervene.");
    else puts("Don't worry. I must intervene.");
  }  
  return 0;
}
