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

typedef long long ll;
const int MAXN = 1000005;
int t, n;
ll dp[MAXN], nums[MAXN], ans, invans, sum;

int
main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0LL, invans = 0LL, sum = 0LL;
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
      dp[i] = nums[i];
      if (i > 0) dp[i] += dp[i - 1];
      if (dp[i] < 0LL) dp[i] = 0LL;
      ans = max(ans, dp[i]);
    }
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      nums[i] *= -1LL;
      dp[i] = nums[i];
      if (i > 0) dp[i] += dp[i - 1];
      if (dp[i] < 0LL) dp[i] = 0LL;
      invans = max(invans, dp[i]);
    }
    cout << max(ans, sum + invans) << endl;
  }
  return 0;
}
