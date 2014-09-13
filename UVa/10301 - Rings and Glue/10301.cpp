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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct Circle {
  double x, y, r;
  Circle (double X, double Y, double R) : x(X), y(Y), r(R) {}  
};

const int MAXN = 105;
int n, p[MAXN], comp[MAXN];
vector <Circle> rings;

double
distan(Circle a, Circle b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double
sumradii(Circle a, Circle b) {
  return (a.r + b.r); 
}

double
diffradii(Circle a, Circle b) {
  return abs(a.r - b.r); 
}

bool
intersect(Circle a, Circle b) {
  double sRadi = sumradii(a, b);
  double dRadi = diffradii(a, b);
  double dCtrs = distan(a, b);
  return (dRadi <= dCtrs && dCtrs < sRadi);
}

void
initialize() {
  for (int i = 0; i <= n; i++) {
    p[i] = i;  
    comp[i] = 0;
  }
}

int
findd(int u) {
  if (p[u] == u) return u;
  return p[u] = findd(p[u]);  
}

void
join(int u, int v) {
  int a = findd(u);
  int b = findd(v);
  if (a == b) return;
  p[a] = b;  
}

int
main() {
  while (cin >> n && n != -1) {
    rings.clear();
    for (int i = 0; i < n; i++) {
      double x, y, r;
      cin >> x >> y >> r;
      rings.push_back(Circle(x, y, r)); 
    }
    initialize();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (intersect(rings[i], rings[j])) {
          join(i, j); 
        }
      } 
    }
    int largest = 0;
    for (int i = 0; i < n; i++) {
      int group = findd(i);
      comp[group]++;
      largest = max(largest, comp[group]);
    }
    printf("The largest component contains %d ring%s.\n", largest, 
      (largest == 1 ? "" : "s"));
  }
  return 0;
}
