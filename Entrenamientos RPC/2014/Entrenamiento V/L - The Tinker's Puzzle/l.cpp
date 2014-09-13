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

int c, h, v;

int
main() {
  cin >> c;
  for (int i = 1; i <= c; i++) {
    cin >> h >> v;
    double sum = (h + (h / 4.0) + (h / 2.0));
    v *= 282;
    double ans = v / (M_PI / 3.0);
    ans /= sum;
    ans = sqrt(ans);
    ans *= 2.0;
    ans += EPS;
    printf("Case %d: %.3f\n", i, ans);
  }  
  return 0;
}
