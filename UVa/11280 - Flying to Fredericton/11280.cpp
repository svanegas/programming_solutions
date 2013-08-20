#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <map>

using namespace std;

const int MAXN = 105;
const long long INF = 1LL << 60;
typedef pair <int, long long> edge;
vector <edge> g[MAXN];
long long l[MAXN][MAXN];
map <string, int> mapa;
int c, n, m, q, z, a, b;
long long cost;
string ciudad, dep, des;

void
limpiar() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
    mapa.clear();
}

void
bellman_ford(int orig) {
    for(int i = 0; i <= n; i++) l[0][i] = INF;
    l[0][orig] = 0;
    for(int i = 1; i <= n-1; i++) {
        for(int u = 0; u < n; u++) l[i][u] = l[i-1][u];
        for(int u = 0; u < n; u++) {
            for(int k = 0; k < g[u].size(); k++) {
                int v = g[u][k].first;
                long long w = g[u][k].second;
                l[i][v] = min(l[i][v], l[i-1][u] + w); 
            } 
        }
    } 
}

int
main() {
    z = 1;
    cin >> c;
    while(c--) {
        cout << "Scenario #" << z++ << endl;
        cin >> n;
        limpiar();
        for(int i = 0; i < n; i++) {
            cin >> ciudad;
            mapa[ciudad] = i;
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> dep >> des >> cost;
            a = mapa[dep];
            b = mapa[des];
            g[a].push_back(edge(b,cost));
        }
        cin >> q;
        bellman_ford(0);
        for(int i = 0; i < q; i++) {
            int stop;
            cin >> stop;
            if (stop > (n-2)) stop = n - 2;
            if(l[stop+1][n-1] == INF) printf("No satisfactory flights\n");
            else printf("Total cost of flight(s) is $%d\n", l[stop+1][n-1]);
        }
        if (c) cout << endl;
    }
    return 0;
}
