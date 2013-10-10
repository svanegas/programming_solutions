#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

struct point{
    double x, y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
};

struct segment{
    point a, b;
    segment() {}
    segment(point A, point B) : a(A), b(B) {}
};

int n, l, h;
double minim;
vector <segment> flaps;

double
distsqr(const point &a, const point &b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double
dist(const point &a, const point &b){
    return sqrt(distsqr(a, b));
}

double distance_point_to_segment(const point &a, const point &b,
                                 const point &pnt) {
    double u = ((pnt.x - a.x)*(b.x - a.x) + (pnt.y - a.y)*(b.y - a.y))/distsqr(a, b);
    point intersection;
    intersection.x = a.x + u*(b.x - a.x);
    intersection.y = a.y + u*(b.y - a.y);
    if (u < 0.0 || u > 1.0) {
        return min(dist(a, pnt), dist(b, pnt));
    }
    return dist(pnt, intersection);
}

int
main() {
    while (cin >> n) {
        cin >> l >> h;
        minim = 999999.0;
        flaps.clear();
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> y;
            x = (i % 2 == 0) ? 0 : l;
            point a = point(x, y);
            cin >> x >> y;
            point b = point(x, y);
            segment r = segment(a, b);
            flaps.push_back(r);
        }
        for (int i = 0; i < n; i++) {
            int lim = (i % 2 == 0) ? l : 0;
            point a = point(lim, 0);
            point b = point(lim, h);
            point pnt = flaps[i].b;
            minim = min(minim, distance_point_to_segment(a, b, pnt));
            if (i < n - 1) {
                point r1 = flaps[i+1].a;
                point r2 = flaps[i+1].b;
                minim = min(minim, distance_point_to_segment(r2, r1, pnt));
            }
        }
        printf("%.2f\n", minim);
    }
    return 0;
}
