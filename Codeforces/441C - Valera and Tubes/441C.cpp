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

int n, m, k, each;
int x, y;

int
main() {
  cin >> n >> m >> k;
  each = (n * m) / k;
  x = y = 1;
  int covered = 0;
  for (int i = 0; i < k - 1; i++) {
    cout << each;
    for (int j = 0; j < each; j++) {
      cout << " " << x << " " << y;
      if (x % 2 == 1) {
        y++;
        if (y > m) {
          x++;
          y = m; 
        }
      }
      else {
        y--;
        if (y < 1) {
          x++;
          y = 1; 
        } 
      }
      covered++;
    }
    puts("");
  }
  cout << ((n * m) - covered);
  for (int i = covered; i < n * m; i++) {
    cout << " " << x << " " << y;
    if (x % 2 == 1) {
      y++;
      if (y > m) {
        x++;
        y = m; 
      }
    }
    else {
      y--;
      if (y < 1) {
        x++;
        y = 1; 
      } 
    }
  }
  puts("");
  return 0;
}
