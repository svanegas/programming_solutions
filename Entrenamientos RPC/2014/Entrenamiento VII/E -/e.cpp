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

const int MAXN = 502;
int t;
int r, c;
char s[MAXN][MAXN];

int
main() {
  ios::sync_with_stdio(false);
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      scanf("%s", s[i]);
    }
    int maxi = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (s[i][j] == '#') {
          int len = 1;
          for (int k = 
          maxi = max(maxi, 1);
        } 
      } 
    }
  }
  return 0;
}
