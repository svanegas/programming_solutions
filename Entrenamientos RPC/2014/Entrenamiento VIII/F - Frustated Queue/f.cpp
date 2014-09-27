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
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 1005;
const int MOD = 1000000;
vector <int> dp1(MAXN);
vector <int> dp2(MAXN);
string s;

int
main() {
  while (getline(cin, s)) {
    int n = s.size();
    for (int i = 0; i <= n; i++) {
      dp1[i] = 0;
      dp2[i] = 0;
    }
    dp1[0] = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') {
        for(int j = 0; j < n - 1; j++) {
          dp2[j+1] = dp1[j];
        }
        dp2[0] = 0;
        for(int j = 1; j < n; j++) {
          dp2[j-1] += dp1[j];
          dp2[j-1] %= MOD;
        }
      } 
      else if (s[i] == '(') {
        for(int j = 0; j < n - 1; j++) {
          dp2[j+1] = dp1[j];
        }
        dp2[0] = 0;
      }
      else {
        for(int j = 1; j < n; j++) {
          dp2[j-1] = dp1[j];
        }
        dp2[n - 1] = 0;
      }
      swap(dp1, dp2);
    }
    cout << dp1[0] << endl;
  }
  return 0;
}
