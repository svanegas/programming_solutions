//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


typedef long long ll;
typedef pair <ll, int> pointValue;

struct point {
  int x, y;
  point (int X, int Y) : x(X), y(Y) {}

  bool operator < (const point &than) const {
    return x < than.x;
  }
};

double
polyArea(const vector <point> &p) {
  double r = 0.0;
  for (int i = 0; i < p.size(); ++i) {
    int j = (i + 1) % p.size();
    r += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return r / 2.0;
}

double
calculateMaxArea(vector <int> xPoints, vector <int> yPoints, int n) {
  sort(yPoints.rbegin(), yPoints.rend());
  ll value[n + 3];
  memset(value, 0, sizeof value);
  priority_queue <pointValue> q;
  for (int i = 1; i < n; ++i) {
    ll distance = xPoints[i] - xPoints[i - 1];
    value[i-1] += distance;
    value[i] += distance;
    q.push(pointValue(value[i-1], xPoints[i-1]));
  }
  q.push(pointValue(value[n - 1], xPoints[n - 1]));
  vector <point> polygon;
  int index = 0;
  while (!q.empty()) {
    pointValue p = q.top(); q.pop();
    polygon.push_back(point(p.second, yPoints[index++]));
  }
  sort(polygon.begin(), polygon.end());
  int xFirstValue = polygon[0].x;
  polygon.insert(polygon.begin(), point(xFirstValue, 0));
  int xLastValue = polygon[n].x;
  polygon.push_back(point(xLastValue, 0));
  polygon.push_back(polygon[0]);
  return polyArea(polygon);
}

int
main() {
  int n;
  while (cin >> n && n != -1) {
    vector <int> xs, ys;
    for (int i = 0; i < n; i++) {
      int xi;
      cin >> xi;
      xs.push_back(xi);
    }
    for (int i = 0; i < n; i++) {
      int yi;
      cin >> yi;
      ys.push_back(yi);
    }
    printf("%.1f\n", abs(calculateMaxArea(xs, ys, n)));
  }
  return 0;
}
