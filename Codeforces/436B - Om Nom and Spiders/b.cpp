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

const int MAXN = 2002;
char park[MAXN][MAXN];
int n, m, k;
int ans[MAXN];

int
main() {
  cin >> n >> m >> k;
  memset(ans, 0, sizeof ans);
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      park[i][j] = getchar();
    }
    getchar();
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - i >= 0 && park[i-i][j] == 'D') ans[j]++;
      if (i + i < n && park[i+i][j] == 'U') ans[j]++;
      if (j - i >= 0 && park[i][j-i] == 'R') ans[j]++;
      if (j + i < m && park[i][j+i] == 'L') ans[j]++;
    } 
  }
  cout << ans[0];
  for (int j = 1; j < m; j++) {
    cout << " " << ans[j]; 
  }
  cout << endl;
  return 0;
}
