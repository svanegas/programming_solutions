using namespace std;

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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define PI acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXM = 4096;
int n;
int dp[MAXM];

int
solve(int mask) {
  //printf("Entro con mask %d\n", mask);
  if (dp[mask] != -1) return dp[mask];
  int mini = 0;
  for (int i = 0; i < 12; i++) if (mask & (1 << i)) mini++;
  //D(mini);
  if (mini == 1) return dp[mask] = 1;
  for (int i = 0; i < 12; i++) {
    if (mask & (1 << i)) {
      if (i - 2 >= 0 && !(mask & (1 << (i - 2))) && (mask & (1 << (i - 1)))) {
        //printf("Con i = %d entro al 1\n", i);
        int newMask = mask;
        newMask &= ~(1 << i);
        newMask &= ~(1 << (i - 1));
        newMask |= (1 << (i - 2));
        mini = min(mini, solve(newMask));
      }
      if (i + 2 < 12 && !(mask & (1 << (i + 2))) && (mask & (1 << (i + 1)))) {
        //printf("Con i = %d entro al 2\n", i);
        int newMask = mask;
        newMask &= ~(1 << i);
        newMask &= ~(1 << (i + 1));
        newMask |= (1 << (i + 2));
        mini = min(mini, solve(newMask));
      }
    }
  }
  return dp[mask] = mini;
}

int
main() {
  cin >> n;
  memset(dp, -1, sizeof dp);
  while (n--) {
    string s; cin >> s;
    int mask = 0;
    for (int i = 0; i < 12; i++) if (s[i] == 'o') mask |= (1 << (11 - i));
    cout << solve(mask) << endl;
  }
  return 0;
}
