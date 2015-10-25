#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3605;
int d[MAXN];
vector <int> buttons;
int n, t;

void
bfs() {
  for (int i = 0; i < MAXN; ++i) d[i] = -1;
  queue <int> q;
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < n; ++i) {
      int next = cur + buttons[i];
      if (next < 0) continue;
      if (next > 3600) next = 3600;
      if (d[next] == -1) {
        d[next] = d[cur] + 1;
        q.push(next);
      }
    }
  }
}
int
main() {
  int z;
  cin >> z;
  while (z--) {
    buttons.clear();
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
      int cur; cin >> cur;
      buttons.push_back(cur);
    }
    bfs();
    int ans = -1;
    int diff = 0;
    for (int i = t; i <= 3600 && ans == -1; ++i) {
      ans = d[i];
      diff = i - t;
    }
    cout << ans << " " << diff << endl;
  }
  return 0;
}
