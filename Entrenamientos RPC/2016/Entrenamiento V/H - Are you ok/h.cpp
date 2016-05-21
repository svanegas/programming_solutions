#include <bits/stdc++.h>

const double EPS = 1e-9;

using namespace std;

struct P {
  int x, y;
  
  P() {}
  P(int _x, int _y) : x(_x), y(_y) {}  
};

int t, n, m;
vector <P> poly;

double polar(P p) {
  if (fabs(p.x) <= EPS && fabs(p.y) <= EPS) return -1.0;
  if (fabs(p.x) <= EPS) return (p.y > EPS ? 1.0 : 3.0) * acos(0);
  double theta = atan(1.0 * p.y / p.x);
  if (p.x > EPS) return (p.y >= -EPS ? theta : (4 * acos(0) + theta));
  return 2 * acos(0) + theta;  
}

bool inside(P p, vector <P> &poly) {
  int n = poly.size();
  double ang = 0.0;
  for (int i = n - 1, j = 0; j < n; i = j++) {
    P v(poly[i].x - p.x, poly[i].y - p.y);
    P w(poly[j].x - p.x, poly[j].y - p.y);
    double va = polar(v);
    double wa = polar(w);
    double xx = wa - va;
    if (va < -0.5 || wa < -0.5 || fabs(fabs(xx) - 2 * acos(0)) < EPS) {
      return false;
    }
    if (xx < -2 * acos(0)) ang += xx + 4 * acos(0);
    else if (xx > 2 * acos(0)) ang += xx - 4 * acos(0);
    else ang += xx;
  }
  return ang * ang > 1.0;
}

int
main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    poly.clear();
    for (int i = 0; i < n; ++i) {
      int x, y; scanf("%d %d", &x, &y);
      poly.push_back(P(x, y));
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      int x, y; scanf("%d %d", &x, &y);
      P p = P(x, y);
      ans += inside(p, poly);
    }
    printf("%d\n", ans);
  }
  return 0;
}
