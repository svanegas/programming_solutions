#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int t, n = 10;
char board[MAXN][MAXN];
int curI, curJ;

int
ind(int i, int j) {
	return i * n + j;	
}

int
calc(int i, int j, vector <int> status) {
	int ans = 0;
	if (i + 2 < n && j + 2 < n && board[i + 2][j + 2] != 'B' &&
		 ((i + 2 == curI && j + 2 == curJ) || board[i + 2][j + 2] != 'W')) {
		if (board[i + 1][j + 1] == 'B' && !status[ind(i + 1, j + 1)]) {
			vector <int> next(status);
			next[ind(i + 1, j + 1)] = 1;
			ans = max(ans, 1 + calc(i + 2, j + 2, next));
		}
	}
	if (i + 2 < n && j - 2 >= 0 && board[i + 2][j - 2] != 'B' &&
	   ((i + 2 == curI && j - 2 == curJ) || board[i + 2][j - 2] != 'W')) {
		if (board[i + 1][j - 1] == 'B' && !status[ind(i + 1, j - 1)]) {
			vector <int> next(status);
			next[ind(i + 1, j - 1)] = 1;
			ans = max(ans, 1 + calc(i + 2, j - 2, next));
		}
	}
	if (i - 2 >= 0 && j + 2 < n && board[i - 2][j + 2] != 'B' &&
	   ((i - 2 == curI && j + 2 == curJ) || board[i - 2][j + 2] != 'W')) {
		if (board[i - 1][j + 1] == 'B' && !status[ind(i - 1, j + 1)]) {
			vector <int> next(status);
			next[ind(i - 1, j + 1)] = 1;
			ans = max(ans, 1 + calc(i - 2, j + 2, next));
		}
	}
	if (i - 2 >= 0 && j - 2 >= 0 && board[i - 2][j - 2] != 'B' &&
	   ((i - 2 == curI && j - 2 == curJ) || board[i - 2][j - 2] != 'W')) {
		if (board[i - 1][j - 1] == 'B' && !status[ind(i - 1, j - 1)]) {
			vector <int> next(status);
			next[ind(i - 1, j - 1)] = 1;
			ans = max(ans, 1 + calc(i - 2, j - 2, next));
		}
	}
	return ans;
}

void
solve() {
	int maxi = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'W') {
				vector <int> v(105, 0);
				curI = i, curJ = j;
				maxi = max(maxi, calc(i, j, v));	
			}
		}
	}
	printf("%d\n", maxi);
}

int
main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < n; ++i) {
			string row; cin >> row;
			for (int j = 0; j < n; ++j) {
				board[i][j] = row[j];
			}
		}
		solve();
	}
	return 0;	
}
