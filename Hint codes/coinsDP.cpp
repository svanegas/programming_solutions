#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

const int MAXN = 1005;
const int INF = 1 << 30;
int dp[MAXN];
int val[] = {1, 3, 5};

int
main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i <= n; i++) dp[i] = INF;
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < sizeof(val)/sizeof(int); j++) {
				if (val[j] <= i && dp[i-val[j]] + 1 < dp[i]) {
					dp[i] = dp[i-val[j]] + 1;
				}
			}
		}
		cout << dp[n] << endl;
	}
    return 0;
}
