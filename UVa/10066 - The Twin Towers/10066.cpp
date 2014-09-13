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

typedef long long ll;
const int MAXN = 105;
int n1, n2;
vector <ll> v1, v2;
int dp[MAXN][MAXN];

int
lcs() {
  for (int j = 0; j <= n2; j++) dp[0][j] = 0;
  for (int i = 0; i <= n1; i++) dp[i][0] = 0;
  
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (v1[i-1] == v2[j-1]) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1); 
      } 
    } 
  }
  return dp[n1][n2];
}

int
main() {
  int z = 1;
  while (cin >> n1 >> n2 && n1 && n2) {
    v1.clear(); v2.clear();
    for (int i = 0; i < n1; i++) {
      ll xi; cin >> xi;
      v1.push_back(xi); 
    }
    for (int i = 0; i < n2; i++) {
      ll xi; cin >> xi;
      v2.push_back(xi);
    }
    int longest = lcs();
    printf("Twin Towers #%d\n", z++);
    printf("Number of Tiles : %d\n\n", longest);
  }
  return 0;
}
