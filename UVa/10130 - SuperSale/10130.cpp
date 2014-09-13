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

const int MAXN = 1005;
const int MAXW = 32;
int t, n, fam, gi, sum;
int dp[MAXN][MAXW];
int w[MAXN], v[MAXN];

int
main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
        for (int i = 0; i <= MAXW; i++) dp[0][i] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < MAXW; j++) 
                if (j - w[i] >= 0) 
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);   
                else
                    dp[i][j] = dp[i-1][j];
        sum = 0;
        cin >> fam;
        while (fam--) {
            cin >> gi;
            sum += dp[n][gi];
        }
        cout << sum << endl;
    }
	return 0;
}
