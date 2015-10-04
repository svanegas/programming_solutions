// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
struct point {
  int x, y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
  bool operator < (const point &than) const {
    if (y > than.y) return true;
    else if (y == than.y) return x < than.x;
    else return false;
  }
};
int n;
vector <point> lamps;

int
solve() {
  sort(lamps.begin(), lamps.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    point cur = lamps[i];
    int lx, rx;
    lx = -INF, rx = INF;
    for (int j = i + 1; j < n; ++j) {
      point next = lamps[j];
      bool right = next.x > cur.x;
      if (right) {
        if (next.x < rx) {
          ans++;
          rx = min(rx, next.x);
        }
      }
      else {
        if (next.x > lx) {
          ans++;
          lx = max(lx, next.x);
        }
      }
    }
  }
  return ans;
}

int
main() {
  while (scanf("%d", &n) != EOF) {
    lamps.clear();
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      lamps.push_back(point(x, y));
    }
    printf("%d\n", solve());
  }
  return 0;
}
