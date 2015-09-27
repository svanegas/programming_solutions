#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> blocks;

int
main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int height;
		cin >> height;
		blocks.push_back(height);
	}
	sort(blocks.begin(), blocks.end());
	int ans = n;
	for (int i = 0; i < n; ++i) {
		int rem_blocks = n - 1 - i;
		int cur_cost = blocks[i] + rem_blocks;
		ans = min(ans, cur_cost);
	}
	cout << ans << endl;
	return 0;	
}
