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

const int MAXN = 1000005;
int arr[MAXN];
int t;

int
main() {
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j += i) {
      arr[j]++; 
    } 
  }
  cin >> t;
  while (t--) {
    int xi; cin >> xi;
    int maxi = 0, ans = 0;
    for (int i = 1; i <= xi; i++) {
      if (maxi < arr[i]) {
        maxi = arr[i];
        ans = i; 
      }
    }
    cout << ans << endl;
  }
  return 0;
}
