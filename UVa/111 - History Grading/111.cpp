//NOT COMPLETED YET

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
int val[MAXN];
map <int, int> m;
int maxi;

int
main() {
    puts("See solution in 111-2.cpp");
    return 0;
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			val[x-1] = i;
		}
		getchar();
		string line;
		while (getline(cin, line)) {
			maxi = -1;
			stringstream ss(line);
			int x;
			for (int i = 0; i < n; i++) {
				ss >> x;
				nums[i] = x;
				dp[i] = 1;
			}
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (val[nums[j]-1] < val[nums[i]-1] 
						&& dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
					maxi = max(maxi, dp[i]);
				}
			}
			cout << maxi << endl;
			for (int i = 0; i < n; i++) {
				cout << dp[i] << " ";
			}
			puts("");
		}
	}
    return 0;
}
