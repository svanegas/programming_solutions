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

typedef pair <int, int> edge;
const int MAXN = 105;
const int INF = 1 << 30;
vector <edge> g[MAXN];
int d[MAXN];
int n, c, a, b, w;

void
limpiar() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

bool bellman_ford(int orig) {
    for (int i = 0; i <= n; i++) d[i] = INF;
    d[orig] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int k = 0; k < g[u].size(); k++) {
                int v = g[u][k].first;
                int peso = g[u][k].second;
                d[v] = min(d[v], d[u] + peso);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < g[i].size(); k++) {
            int v = g[i][k].first;
            int peso = g[i][k].second;
            if (d[v] > d[i] + peso) {
                return true;
            }
        }
    }
    return false;
}

int
main() {
    while (scanf("%d%d", &n, &c) && n && c) {
        limpiar();
        for (int i = 0; i < c; i++) {
            scanf("%d%d%d", &a, &b, &w);
            g[a-1].push_back(edge(b-1,w));
            g[b-1].push_back(edge(a-1,w*-1));
        }
        if (bellman_ford(0)) puts("Y");
        else puts("N"); 
    }
    return 0;
}
