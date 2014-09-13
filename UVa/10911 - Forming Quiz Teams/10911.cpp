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
const int MAXN = 20;
double dist[MAXN][MAXN], x[MAXN], y[MAXN], dp[1 << 16];
int n;

double
distan(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));  
}

double
solve(int mask) {
  if (dp[mask] > -1.0) return dp[mask];
  if (mask == (1 << (2 * n)) - 1) return dp[mask] = 0.0;
  
  double ans = INF * 1.0;
  int p1, p2;
  for (p1 = 0; p1 < 2 * n; p1++) {
    if (!(mask & (1 << p1))) break; 
  }
  for (p2 = p1 + 1; p2 < 2 * n; p2++) {
    if (!(mask & (1 << p2))) {
      ans = min(ans, dist[p1][p2] + solve(mask | (1 << p1) | (1 << p2)));
    }
  }
  return dp[mask] = ans;
}

int
main() {
  int z = 1;
  while (cin >> n && n) {
    for (int i = 0; i < 2 * n; i++) {
      string trash;
      cin >> trash >> x[i] >> y[i];
    } 
    for (int i = 0; i < 2 * n; i++) {
      for (int j = i + 1; j < 2 * n; j++) {
        dist[i][j] = dist[j][i] = distan(x[i], y[i], x[j], y[j]);
      } 
    }
    
    for (int i = 0; i <= (1 << 2 * n); i++) dp[i] = -1.0;
    double ans = solve(0);
    printf("Case %d: %.2f\n", z++, ans);
  }
  return 0;
}
