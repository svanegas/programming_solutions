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

string s, t;
int n, m;

int
main() {
  while (cin >> s && s != "0") {
    cin >> t;
    n = s.size(); m = t.size();
    for (int i = 0; i < m; ++i) {
      int sum = s[i % n];
      int add = t[i] - 'A' + 1;
      int res = sum + add;
      res %= ('Z' + 1);
      if (res < 'A') res += 'A';
      printf("%c", char(res));
    }
    puts("");
  }
  return 0;
}
