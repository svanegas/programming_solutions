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

const int MAXN = 10005;
const int INF = 1 << 30;
int n;
int dp[MAXN];

int
main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> dp[i];
            if (i > 0) dp[i] += dp[i-1];
            if (dp[i] < 0) dp[i] = 0;   
        }
        int maxi = -1*INF;
        for (int i = 0; i < n; i++) maxi = max(maxi, dp[i]);
        if (maxi > 0) printf("The maximum winning streak is %d.\n", maxi);
        else puts("Losing streak.");
    }
	return 0;
}
