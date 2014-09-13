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

const int MAXN = 1000005;
int res[MAXN];
int a;

int
main() {
  cin >> a;
  memset(res, 0, sizeof res);
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j += i) {
       res[j]++;
    } 
  }
  while (a--) {
    int n; cin >> n;
    int maxi = -1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (res[i] > maxi) {
        maxi = res[i];
        ans = i; 
      }
    }
    cout << ans << endl;
  }
  return 0;
}
