
using namespace std;
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <list>
#include <map>
#include <set>

//team550
//53763843

#define D(x) cout << #x " = " << (x) << endl

template <class T> string toStr(const T &x) {
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x) {
stringstream s; s << x; int r; s >> r; return r;
}

struct point {
    int x, y;
    point() {}
    point (int X, int Y) : x(X), y(Y) {}
    bool operator < (const point &that) const {
        if (x < that.x) return true;
        if (x == that.x) {
            if (y < that.y) return true;
            else return false;
        }
        return false;
    }
};

vector <point> points;

int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        points.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            point p = point(x, y);
            points.push_back(p);
        }
        sort(points.begin(), points.end());
        double ctr;
        if (n % 2 == 1) {
            ctr = points[n/2].x;
        }
        else {
            double a = (points[n/2].x - points[(n/2) - 1].x) / 2.0;
            ctr = double(points[n/2].x) - a;
        }
        bool symetric = true;
        for (int i = 0; i < n && symetric; i++) {
            if (points.front().x - ctr != -1*(points.back().x - ctr)) symetric = false;
        }
        if (symetric) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
