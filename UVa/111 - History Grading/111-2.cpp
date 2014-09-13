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

const int MAXN = 22;
int n;
map <int, int> val;
string line;
int dp[MAXN];
int v[MAXN];

int
lis() {
    int maxi = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (val[v[i]] > val[v[j]] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                maxi = max(maxi, dp[i]);
            }
        }   
    }
    return maxi;
}


int
main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int xi; cin >> xi;
        val[i] = xi;
    }
    getchar();
    while (getline(cin, line)) {
        stringstream ss(line);
        int token;
        int i = 1;
        while (ss >> token) {
            v[token] = (i++);
        }
        cout << lis() << endl;
    }
	return 0;
}
