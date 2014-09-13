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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;

struct point {
  ll x, y;
  point () {}
  point (ll X, ll Y) : x(X), y(Y) {}  
};

point pivot;
int n;

inline ll distsqr(const point &a, const point &b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); 
}

inline double dist(const point &a, const point &b) {
  return sqrt(distsqr(a, b)); 
}

inline ll cross(const point &a, const point &b, const point &c) {
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);   
}

bool angleCmp (const point &self, const point &that) {
  ll t = cross(pivot, that, self);
  if (t < 0) return true;
  if (t == 0) {
    return (distsqr(pivot, self) < distsqr(pivot, that)); 
  } 
  return false;
}

vector<point> graham(vector<point> p) {
  for (int i = 1; i < p.size(); i++) {
    if (p[i].y < p[0].y ||
        (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }  
  
  pivot = p[0];
  sort(p.begin(), p.end(), angleCmp);
  
  vector <point> chull(p.begin(), p.begin() + 3);
  
  for (int i = 3; i < p.size(); i++) {
    while (chull.size() >= 2 && cross(chull[chull.size() - 2],
                                      chull[chull.size() - 1],
                                      p[i]) <= 0) {
      chull.erase(chull.end() - 1);                                    
    } 
    chull.push_back(p[i]);
  }
  return chull;
}

int
main() {
  cout << "Wrong Answer" << endl;
  return 0;
  while (cin >> n) {
    vector <point> puntos;
    for (int i = 0; i < n; i++) {
      ll xi, yi; cin >> xi >> yi;
      point po = point(xi, yi);
      puntos.push_back(po);
    } 
    vector <point> res = graham(puntos);
    cout << n << endl;
    for (int i = 0; i < res.size(); i++) {
      point po = res[i];
      cout << po.x << " " << po.y << endl;
    }
  }
  return 0;
}
