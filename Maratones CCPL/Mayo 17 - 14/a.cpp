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
};

struct edge {
    int start, endd;
    double weight;
    edge(int u, int v, double w) {
        start = u; endd = v; weight = w;
    }
    bool operator < (const edge &other) const {
        return weight < other.weight;
    }
};

inline int distsqr(const point &a, const point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
inline double dist(const point &a, const point &b) {
    return sqrt(distsqr(a, b));
}

const int MAXN = 505;
int t, n, s;
vector <point> points;
vector <edge> edges;
int p[MAXN];

void
initialize() {
    for (int i = 0; i <= n; i++) p[i] = i;
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

double
kruskal() {
    initialize();
    sort(edges.begin(), edges.end());
    double maxi = 0;
    int agreg = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (n - agreg == s) break;
        int u = edges[i].start;
        int v = edges[i].endd;
        double w = edges[i].weight;
        if (findd(u) != findd(v)) {
            agreg++;
            maxi = max(maxi, w);
            join(u, v);
        }
    }
    return maxi;
}

int main() {
    cin >> t;
    while (t--) {
        points.clear();
        edges.clear();
        cin >> s >> n;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            point a = point(x, y);
            points.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double distan = dist(points[i], points[j]);
                edge e = edge(i, j, distan);
                edges.push_back(e);
            }
        }
        printf("%.2f\n", kruskal());
    }
    return 0;
}
