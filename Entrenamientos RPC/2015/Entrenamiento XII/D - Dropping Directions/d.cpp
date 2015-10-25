#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
int n, goal;
int g[MAXN][5];
bool visited[MAXN][3];

bool
dfs(int s, int dir) {
  visited[s][dir % 2] = true;
  bool found_goal = s == goal;
  int next = g[s][(dir + 2) % 4];
  int next_dir;
  for (next_dir = 0; g[next][next_dir] != s; ++next_dir);
  assert(next_dir < 4);
  if (!visited[next][next_dir % 2]) found_goal |= dfs(next, next_dir);
  return found_goal;
}

int
main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &goal); goal--;
    for (int i = 0; i < n; ++i) {
      visited[i][0] = visited[i][1] = false;
      for (int j = 0; j < 4; ++j) {
        scanf("%d", &g[i][j]); g[i][j]--;
      }
    }
    int signs = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (!visited[i][j]) signs += (!dfs(i, j));
      }
    }
    printf("%d\n", signs);
  }
  return 0;
}
