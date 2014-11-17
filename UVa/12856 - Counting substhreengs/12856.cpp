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

const int MAXN = 1000005;
int modsum[MAXN];
ll seen[3][MAXN];

ll
solve(const string &s) {
  ll ans = 0LL;
  int n = s.size();
  modsum[0] = 0;
  for (int i = 0; i < n; ++i) {
    int val = s[i] - '0';
    modsum[i + 1] = (modsum[i] + val) % 3;
  }
  seen[0][0] = 1LL; seen[1][0] = seen[2][0] = 0LL;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < 3; ++k) {
      int val = modsum[i + 1];
      seen[k][i + 1] = seen[k][i] + (val == k);
      ans += (val == k) ? seen[k][i + 1] - 1 : 0;
    }
  }
  return ans;
}

int
main() {
  string s;
  while (cin >> s) {
    int n = s.size();
    int ind = 0;
    string num = "";
    ll ans = 0LL;
    while (ind < n) {
      if (isdigit(s[ind])) num += s[ind];
      else {
        if (num != "") ans += solve(num);
        num = "";
      }
      ind++;
    }
    if (num != "") ans += solve(num); 
    cout << ans << endl;
  }
  return 0;   
}
