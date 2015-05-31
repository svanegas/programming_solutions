#include <bits/stdc++.h>

using namespace std;

template <class T> int toInt(const T &x) {
  stringstream s; s << x; int r; s >> r; return r;
}

template <class T> string toStr(const T &x) {
  stringstream s; s << x; return s.str();
}

const int MAXN = 1000005;
int d[MAXN];
int t, n;

int
rev(int x) {
  string cur = toStr(x);
  reverse(cur.begin(), cur.end());
  return toInt(cur);
}

void
bfs(int s) {
  for (int i = 0; i < MAXN; ++i) d[i] = -1;
  queue <int> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    // Next number (step 1)
    int next = cur + 1;
    if (next <= MAXN && d[next] == -1) {
      d[next] = d[cur] + 1;
      q.push(next);
    }
    // Reversing number
    next = rev(cur);
    if (next <= MAXN && d[next] == -1) {
      d[next] = d[cur] + 1;
      q.push(next);
    }
  }
}
int
main() {
  bfs(1);
  scanf("%d", &t);
  for (int z = 1; z <= t; ++z) {
    scanf("%d", &n);
    printf("Case #%d: %d\n", z, d[n]);
  }
  return 0;
}
