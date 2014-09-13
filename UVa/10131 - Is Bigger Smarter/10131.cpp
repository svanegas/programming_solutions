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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct eleph {
  int w, q, ind;
  eleph() {}
  eleph(int W, int Q, int IND) : w(W), q(Q), ind(IND) {}
  
  bool operator <(const eleph &e2) const {
    return w < e2.w; 
  }
};

const int MAXN = 1005;
vector <eleph> e;
int dp[MAXN];
int p[MAXN];

void
solve(int n) {
  int maxi = -1, ini = -1;
  dp[0] = 1;
  p[0] = -1;
  int i;
  for (i = 1; i < n; i++) {
    dp[i] = 1;
    p[i] = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (e[i].w > e[j].w && e[i].q < e[j].q && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        p[i] = j;
        if (maxi < dp[i]) {
          maxi = dp[i]; 
          ini = i;
        }
      }
    }   
  }
  
  stack <int> s;
  while (ini != -1) {
    s.push(e[ini].ind);
    ini = p[ini];
  }
  cout << maxi << endl;
  while (!s.empty()) {
    cout << (s.top()) << endl;
    s.pop();
  }
}

int
main() {
  int wi, qi, n = 0;
  while (cin >> wi >> qi) {
    eleph ai = eleph(wi, qi, n+1);
    e.push_back(ai);
    n++;
  }
  sort(e.begin(), e.end());
  solve(n);
  return 0;
}
