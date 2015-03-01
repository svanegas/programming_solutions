//Just Code It.
using namespace std;
#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x "=" << (x) << endl

const double EPS = 1e-9;
typedef long long ll;

struct point {
    int x, y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

point pivot;

inline int distsqr(const point &a, const point &b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b) {
    return sqrt(distsqr(a, b));
}

inline int cross(const point &a, const point &b, const point &c) {
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

bool angleCmp(const point &self, const point &that) {
    int t = cross(pivot, that, self);
    if (t < 0) return true;
    if (t == 0) {
        return (distsqr(pivot, self) < distsqr(pivot, that));
    }
    return false;
}

vector <point> graham(vector <point> p) {
    for (int i = 1; i < p.size(); i++) {
        if (p[i].y < p[0].y ||
            (p[i].y == p[0].y && p[i].x < p[0].x))
            swap(p[0], p[i]);
    }
    pivot = p[0];
    sort(p.begin(), p.end(), angleCmp);

    vector <point> chull(p.begin(), p.begin() + 3);

    for (int i = 3; i < p.size(); i++) {
        while (chull.size() >= 2 &&
               cross(chull[chull.size() - 2],
                     chull[chull.size() - 1],
                     p[i]) <= 0) {
            chull.erase(chull.end() - 1);
        }
        chull.push_back(p[i]);
    }
    return chull;
}

double polarAngle(point p) {
    if (fabs(p.x) <= EPS && fabs(p.y) <= EPS) return -1.0;
    if (fabs(p.x) <= EPS) return (p.y > EPS ? 1.0 : 3.0) * acos(0);
    double theta = atan(1.0 * p.y / p.x);
    if (p.x > EPS) return (p.y >= -EPS ? theta : (4*acos(0) + theta));
    return (2 * acos(0) + theta);
}

bool pointInPoly(point p, vector<point> &poly) {
    int n = poly.size();
    double ang = 0.0;
    for (int i = n - 1, j = 0; j < n; i = j++) {
        point v(poly[i].x - p.x, poly[i].y - p.y);
        point w(poly[j].x - p.x, poly[j].y - p.y);
        double va = polarAngle(v);
        double wa = polarAngle(w);
        double xx = wa - va;
        if (va < -0.5 || wa < -0.5 || fabs(fabs(xx)-2*acos(0)) < EPS) {
          puts("Entro");
            //Point is on the edge
            return true;
            //assert(false);
            //ang += 2 * acos(0);
            //continue;
        }
        if (xx < -2 * acos(0) ) ang += xx + 4 * acos(0);
        else if (xx > 2 * acos(0) ) ang += xx - 4 * acos(0);
        else ang += xx;
    }
    return (ang * ang > 1.0);
}

double turn(const point &a, const point &b, const point &c) {
    double z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (fabs(z) < 1e-9) return 0.0;
    return z;
}

bool insideConvexPolygon(const vector <point> &p, const point &a) {
    int mask = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double z = turn(p[i], p[j], a);
        if (z < 0.0) {
            mask |= 1;
        }
        else if (z >= 0.0) {
            mask |= 2;
        }
        else if (z == 0.0) return false;
        if (mask == 3) return false;
    }
    return mask != 0;
}

int m, c;

int main() {
    while (cin >> m >> c && (m || c)) {
        vector <point> mCity;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            mCity.push_back(point(x, y));
        }
        mCity = graham(mCity);
        bool can = true;
        for (int i = 0; i < c; i++) {
            int x, y;
            cin >> x >> y;
            point test = point(x, y);
            if (pointInPoly(test, mCity)) {
                can = false;
            }
        }
        if (can) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
