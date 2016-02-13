#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
  point() { }
  point(double _x, double _y) : x(_x), y(_y) { }
};

vector <point> poly;
map <string, int> m;
int t, n;

double
area(const vector<point> &p) {
  double r = 0.0;
  for (int i = 0; i < p.size(); ++i) {
    int j = (i + 1) % p.size();
    r += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return r / 2.0;
}

double rad(double deg) {
  return (acos(-1.0) / 180.0) * deg;
}

int
main() {
  m["x"] = 0;
  m["y"] = 60;
  m["z"] = 120;
  m["-x"] = 180;
  m["-y"] = 240;
  m["-z"] = 300;
  vector <point> trian;
  trian.push_back(point(0.0, 0.0));
  trian.push_back(point(1.0, 0.0));
  trian.push_back(point(1.0 + cos(rad(120 * 1.0)), sin(rad(120 * 1.0))));
  double trian_area = area(trian);
  cin >> t;
  while (t--) {
    poly.clear();
    cin >> n;
    double curX, curY;
    curX = curY = 0.0;
    poly.push_back(point(curX, curY));
    for (int i = 0; i < n; ++i) {
      string dir;
      int len;
      cin >> dir >> len;
      int ang = len < 0 ? m["-" + dir] : m[dir];
      curX += cos(rad(ang * 1.0)) * abs(len * 1.0);
      curY += sin(rad(ang * 1.0)) * abs(len * 1.0);
      if (i != n - 1) poly.push_back(point(curX, curY));
    }
    printf("%.0f\n", abs(round(area(poly) / trian_area)));
  }
  return 0;
}
