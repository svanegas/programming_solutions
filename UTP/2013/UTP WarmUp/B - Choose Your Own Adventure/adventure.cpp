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

const int MAXN = 5005;
const int INF = 1 << 30;
vector <int> g[MAXN];
map <int, int> fin;
vector <pair <int, int> > pend;
int d[MAXN], color[MAXN], dist;
enum {WHITE, GRAY, BLACK};

void
dfs(int u, int recorrido) {
    color[u] = GRAY;
    dist = max(dist, recorrido);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (color[v] == WHITE) dfs(v, recorrido + 1);   
    }
    color[u] = BLACK;
}

int
call_dfs(int nodo, int n) {
    dist = 0;
    for (int i = 0; i <= n; i++) color[i] = WHITE;
    dfs(nodo, 1);
    return dist;
}

int
bfs(int s, int n) {
    int minim = INF;
    for (int i = 1; i <= n; i++) d[i] = -1;
    queue <int> q;
    q.push(s);
    d[s] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i];
            if (d[next] == -1) {
                d[next] = d[cur] + 1;
                if (g[next].size() == 0) minim = min(minim, d[next]);
                q.push(next);   
            }   
        }
    }
    if (minim == INF) return 1;
    return minim;    
}

int
main() {
    int cant_nodos = 0;
    int z = 1;
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i <= cant_nodos; i++) g[i].clear();
        fin.clear();
        pend.clear();
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, p; cin >> a >> b >> p;
            
            cant_nodos = max(cant_nodos, b);
            
            for (int j = a; j < b; j++) {
                g[j].push_back(j+1);
            }
            fin[i] = b;
            if (p != -1) pend.push_back(make_pair(p, a));
        }
        for (int i = 0; i < pend.size(); i++) {
            int a, b;
            a = fin[pend[i].first];
            b = pend[i].second;
            g[a].push_back(b);   
        }
        
        int q; cin >> q;
        printf("Case %d:\n", z++);
        for (int i = 0; i < q; i++) {
            int xq; cin >> xq;
            printf("%d %d\n", bfs(xq, cant_nodos), call_dfs(xq, cant_nodos));
        }
    }
    return 0;
}
