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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 10005;
ll num[MAXN][10];
int t, n;

void
build() {
  for (int j = 0; j <= 9; ++j) num[1][j] = 0LL;
  num[1][1] = 1LL;
  for (int i = 2; i <= 10000; ++i) {
    for (int j = 0; j <= 9; ++j) {
      num[i][j] = num[i-1][j];
    }
    int k = i;
    while (k > 0) {
      int digit = k % 10;
      k /= 10;
      num[i][digit]++;
    }
  }
}

int main() {
  build();
  cin >> t;
  while (t--) {
    cin >> n;
    cout << num[n][0];
    for (int j = 1; j <= 9; ++j) cout << " " << num[n][j];
    cout << endl; 
  }
  return 0;
}

