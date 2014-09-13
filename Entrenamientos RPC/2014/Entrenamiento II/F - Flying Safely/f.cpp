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

struct edge {
    int start, end, weight;
    edge(int u, int v, int w) {
        start = u; end = v; weight = w;   
    }
    bool operator < (const edge &other) const {
        return weight < other.weight;   
    }
};

const int MAXN = 1005;
vector <edge> edges;
int p[MAXN];
int t, n, m;

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
kruskal (int n) {
    for (int i = 0; i <= n; i++) p[i] = i;
    sort(edges.begin(), edges.end());
    
    int total = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].start;
        int v = edges[i].end;
        int w = edges[i].weight;
        if (findd(u) != findd(v)) {
            total += w;
            join(u, v);   
        }   
    }    
    return total;
}

int
main() {
    cin >> t;
    while (t--) {
        edges.clear();
        cin >> n >> m;
        while (m--) {
            int ini, fin;
            cin >> ini >> fin;
            ini--; fin--;
            edges.push_back(edge(ini, fin, 1));
            edges.push_back(edge(fin, ini, 1));
        }
        cout << kruskal(n) << endl;
    }
    return 0;
}
