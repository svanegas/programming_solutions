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

//157.253.238.31
//team608
//539207a2

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 15;
unsigned long long dp[MAXN+5][MAXN+5];

int x, y, z;

int
main() {
  for(int i = 0; i <= MAXN; ++i) {
    dp[i][1] = 1;
    dp[i][0] = 1;
    dp[0][i] = 1;
  }
  
  for(int i = 1; i <= MAXN; ++i) {
    for(int j = 2; j <= MAXN; ++j) {
      dp[i][j] = 0;
      for (int k = i; k >= 0; k--) {
        dp[i][j] += ((dp[i - k][j-1]) % 1000000);
      }
    }
  }
  while(cin >> x >> y >> z){
    int sum = 10 - x - y - z;
    cout << dp[sum][3] << endl;
  }
  return 0;
}
