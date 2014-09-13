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

const int INF = 1 << 30;
const int MAXS = 305;
const int MAXA = 52;
int dp[MAXS];
int arrow[MAXA];
int p[MAXS];
int used[MAXS];

int cases, a, s;

void
solve() {
  dp[0] = 0;
  p[0] = -1;
  for (int i = 1; i <= s; i++) {
    int mini = INF;
    p[i] = -1;
    used[i] = -1;
    for (int j = 0; j < a; j++) {
      if (i - arrow[j] >= 0) {
        if (dp[i - arrow[j]] < mini) {
          mini = dp[i - arrow[j]];
          p[i] = i - arrow[j];
          used[i] = arrow[j];
        }
      }
    }
    dp[i] = 1 + mini;
  }  
}

int
main() {
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    cin >> a >> s;
    for (int i = 0; i < a; i++) cin >> arrow[i];
    sort(arrow, arrow + a, greater<int>());
    solve();
    if (dp[s] < INF) {
      vector <int> aUsed;
      int next = s;
      while (p[next] != -1) {
        aUsed.push_back(used[next]);
        next = p[next];
      }
      printf("Case %d: [%d] ", cas, dp[s]);
      cout << aUsed[0];
      for (int i = 1; i < aUsed.size(); i++) {
        cout << " " << aUsed[i]; 
      } 
      puts("");
    }
    else printf("Case %d: impossible\n", cas);
  }
  return 0;
}
