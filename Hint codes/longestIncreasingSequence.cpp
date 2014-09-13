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
int dp[MAXN];
int nums[MAXN];
int maxi;

int
main() {
	int n;
	while (cin >> n && n) {
		maxi = -1;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			dp[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
				maxi = max(maxi, dp[i]);
			}
		}
		cout << maxi << endl;
	}
    return 0;
}
