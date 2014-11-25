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

typedef long long ll;
int spaces, one = 0, two = 0;
string turn;
ll ans = 0LL;

int
main() {
  cin >> spaces;
  cin >> turn;
  for (int i = 0; i < turn.size(); ++i) {
    if (turn[i] == '1') {
      if (one + (two * 2) + 1 <= spaces) one++;
      else if (two > 0) {
        two--;
        one++;
      }
    }
    else {
      if (one + (two * 2) + 2 <= spaces) two++; 
    }
    ans += (two + one);
  }
  cout << ans << endl;
  return 0;
}
