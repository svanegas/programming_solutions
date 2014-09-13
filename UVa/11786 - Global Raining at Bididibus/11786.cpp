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

int t;

int
main() {
  cin >> t;
  getchar();
  while (t--) {
    char c;
    stack <int> s;
    int i = 0, ans = 0;
    while ((c = getchar()) && c != '\n') {
      switch (c) {
        case '/':
          if (s.size() > 0) {
            ans += (i - s.top());
            s.pop();
          }
          break;
        case '\\':
          s.push(i);
          break;
      }
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
