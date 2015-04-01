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

int t;
int found = -1;

int
solve(int board, int ticks, int clicked) {
  if (board == 0) return found = ticks;
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int pressing = i * 3 + j;
      if (clicked & (1 << pressing)) continue;
      int next = board;
      if (i - 1 >= 0) next ^= (1 << ((i - 1) * 3 + j));
      if (i + 1 < 3) next ^= (1 << ((i + 1) * 3 + j));
      if (j - 1 >= 0) next ^= (1 << (i * 3 + (j - 1)));
      if (j + 1 < 3) next ^= (1 << (i * 3 + (j + 1)));
      next ^= (1 << pressing);
      ans = solve(next, ticks + 1, clicked | (1 << pressing));
      if (found != -1) return ans;
    }
  }
  return ans;
}

int
main() {
  cin >> t;
  while (t--) {
    found = -1;
    int board = 0;
    for (int i = 0; i < 3; ++i) {
      string s; cin >> s;
      for (int j = 0; j < 3; ++j) {
        if (s[j] == '*') board |= (1 << (i * 3 + j));
      }
    }
    cout << solve(board, 0, 0) << endl;
  }
  return 0;
}

