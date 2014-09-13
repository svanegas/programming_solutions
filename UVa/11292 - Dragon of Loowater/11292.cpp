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

int n, m, ans;
priority_queue <int, vector<int>, greater<int> > heads;
priority_queue <int, vector<int>, greater<int> > knights;

bool
solve() {
  if (n > m) return false;
  while (!heads.empty() && !knights.empty()) {
    int val = heads.top(); heads.pop();
    while (!knights.empty()) {
      int poss = knights.top(); knights.pop();
      if (poss >= val) {
        ans += poss;
        break;
      }
    } 
  }
  if (heads.empty()) return true;
  else return false;
}

int
main() {
  while (cin >> n >> m && n && m) {
    ans = 0;
    heads = priority_queue <int, vector<int>, greater<int> >();
    knights = priority_queue <int, vector<int>, greater<int> >();
    for (int i = 0; i < n; i++) {
      int xi; cin >> xi;
      heads.push(xi);
    }
    for (int i = 0; i < m; i++) {
      int xi; cin >> xi;
      knights.push(xi); 
    }
    if (solve()) printf("%d\n", ans);
    else puts("Loowater is doomed!");
  }
  return 0;
}
