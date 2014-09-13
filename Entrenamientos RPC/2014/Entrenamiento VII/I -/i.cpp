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

struct point {
  int x, y;
  point (int X, int Y) : x(X), y(Y) { }  
};

inline int distsqr(const point &a, const point &b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); 
}

inline double dist(const point &a, const point &b) {
  return sqrt(distsqr(a, b));  
}

double
halfPerimeter(double a, double b, double c) {
  return (a + b + c) / 2;  
}

double
area(double a, double b, double c, double p) {
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool
isosceles(const point &a, const point &b, const point &c) {
  double d1 = abs(dist(a, b));
  double d2 = abs(dist(b, c));
  double d3 = abs(dist(c, a));
  if (d1 == d2 && d1 != d3 ||
      d1 == d3 && d1 != d2 ||
      d2 == d3 && d1 != d2) {
    double p = halfPerimeter(d1, d2, d3);
    double a = area(d1, d2, d3, p);
    if (a == 0.0) return false;
    else return true;    
  }
  return false;
}

int n;

int
main() {
  while (cin >> n) {
    vector <point> points;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points.push_back(point(x, y));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (isosceles(points[i], points[j], points[k])) {
            ans++;
          }
        } 
      } 
    }
    cout << ans << endl;
  }
  return 0;
}
