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

//157.253.238.31
//team608
//539207a2

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int t, n;
string s;

int
main() {
  cin >> t;
  for (int cas = 1; cas <= t; cas++) {
    cin >> n;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') {
        ans++;
        i += 2;
      } 
    }
    printf("Case %d: %d\n", cas, ans);
  }
  return 0;
}
