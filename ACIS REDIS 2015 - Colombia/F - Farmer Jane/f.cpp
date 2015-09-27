// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y, w;
  point () {}
  point(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
};

vector <point> poly;

double cx() {
  double ans = 0.0;
  for (int i = 0; i < poly.size(); ++i) ans += poly[i].x;
  return ans;
}

double cy() {
  double ans = 0.0;
  for (int i = 0; i < poly.size(); ++i) ans += poly[i].y;
  return ans;
}

double
watering(double x, double y) {
  double ans = 0.0;
  for (int i = 0; i < poly.size(); ++i) {
    point p = poly[i];
    ans += p.w * ((p.x * 1.0 / p.w - x) * (p.x * 1.0 / p.w - x) +
                  (p.y * 1.0 / p.w - y) * (p.y * 1.0 / p.w - y));
  }
  return ans;
}

int
main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    poly.clear();
    int w_tot = 0;
    for (int i = 0; i < n; ++i) {
      int x, y, w;
      scanf("%d %d %d", &x, &y, &w);
      poly.push_back(point(x * w, y * w, w));
      w_tot += w;
    }
    double cX = cx() / (w_tot * 1.0), cY = cy() / (w_tot * 1.0);
    printf("%.3f\n", watering(cX, cY));
  }
  return 0;
}
