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

int n;

string
go(string s) {
  if (s.size() == 7) {
    int val = 0;
    for (int i = 0; i < 7; ++i) {
      if (s[i] == '+') val += ((int) pow(3.0, i * 1.0)); 
      if (s[i] == '-') val -= ((int) pow(3.0, i * 1.0)); 
    }
    if (val == n) return s;
    else return "!";
  }
  else {
    string next = go(s + '+');
    if (next != "!") return next;
    next = go(s + '0');
    if (next != "!") return next;
    return go(s + '-');
  }
}

int
main() {
  cin >> n;
  string ans = go("");
  reverse(ans.begin(), ans.end());
  while (!ans.empty() && ans[0] == '0') ans.erase(ans.begin());
  cout << ans << endl;
  return 0;
}
