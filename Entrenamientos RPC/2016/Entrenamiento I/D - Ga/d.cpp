#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
char board[MAXN][MAXN];
bool seen[MAXN][MAXN];
int t, n;
enum { WHITE='w', BLACK='b', EMPTY='-' };
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void
dfs(int sI, int sJ) {
  seen[sI][sJ] = true;
  for (int i = 0; i < 8; ++i) {
    if (sI + dx[i] >= 0 && sI + dx[i] < n &&
        sJ + dy[i] >= 0 && sJ + dy[i] < n &&
        board[sI + dx[i]][sJ + dy[i]] == EMPTY &&
        !seen[sI + dx[i]][sJ + dy[i]]) dfs(sI + dx[i], sJ + dy[i]);
  }
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n; cin.ignore();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        seen[i][j] = false;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%c", &board[i][j]);
      }
      cin.ignore();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == WHITE && !seen[i][j]) dfs(i, j);
      }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        count += board[i][j] == EMPTY && seen[i][j];
      }
    }
    cout << count << endl;
  }
  return 0;
}
