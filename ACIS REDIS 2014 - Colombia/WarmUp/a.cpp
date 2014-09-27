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

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 15;
int dp[MAXN][MAXN];

void
build() {
    for (int j = 1; j < MAXN; j++) dp[1][j] = 1, dp[j][0] = 1;
    for (int i = 2; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
    }
}

int
main() {
    build();
    int d, m, s;
    while (cin >> d >> m >> s) {
        int tot = 10 - (d + m + s);
        cout << dp[3][tot] << endl;
    }
    return 0;
}
