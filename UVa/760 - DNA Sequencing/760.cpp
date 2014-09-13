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

const int MAXN = 305;
string s, t;
set <string> res;
int n, m;
int dp[MAXN][MAXN];

string
backtrack(int i, int j, string p) {
  if (dp[i][j] == 0) {
    reverse(p.begin(), p.end());
    return p; 
  }
  else {
    p += s[i-1];
    return backtrack(i-1, j-1, p); 
  }
}

void
lcsubstr() {
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int j = 0; j <= m; j++) dp[0][j] = 0;
  
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        if (dp[i-1][j-1] + 1 == maxi) {
          string p = backtrack(i, j, "");
          res.insert(p);
        }
        else if (dp[i-1][j-1] + 1 > maxi) {
          res.clear();
          string p = backtrack(i, j, "");
          res.insert(p);
          maxi = dp[i-1][j-1] + 1;
        }
      }
      else dp[i][j] = 0;
    } 
  } 
}

int
main() {
  int cas = 0;
  while (getline(cin, s) && getline(cin, t)) {
    if (cas) printf("\n");
    res.clear();
    n = s.size(), m = t.size();
    if (m > n) {
      swap(s, t);
      swap(n, m); 
    }
    lcsubstr();
    if (res.empty()) printf("No common sequence.\n");
    else {
      set <string> :: iterator it;
      for (it = res.begin(); it != res.end(); it++) {
        printf("%s\n", (*it).c_str()); 
      } 
    }
    getline(cin, s);
    cas++;
  }
  return 0;
}
