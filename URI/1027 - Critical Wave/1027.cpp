#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;

  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}

  bool operator < (const point &than) const {
    if (x < than.x) return true;
    else if (x == than.x) return y < than.y;
    else return false;
  }
};

const int MAXN = 1005;
int dp[MAXN][2];
vector <point> points;
int n;

int
solve() {
  for (int i = 0; i < n; ++i) {
    dp[i][0] = dp[i][1] = 1;
    for (int j = i - 1; j >= 0; --j) {
      const point &a = points[j];
      const point &b = points[i];
      if (b.x > a.x) {
        if (b.y - a.y == 2) {
          dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        }
        if (a.y - b.y == 2) {
          dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
      }
    }
  }
  int maxi = 1;
  for (int i = 0; i < n; ++i) {
    maxi = max(maxi, max(dp[i][0], dp[i][1]));
  }
  return maxi;
}

int
main() {
  while (cin >> n) {
    points.clear();
    for (int i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      point p = point(x, y);
      points.push_back(p);
    }
    sort(points.begin(), points.end());
    cout << solve() << endl;
  }
  return 0;
}
