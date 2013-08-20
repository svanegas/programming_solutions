#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, int> dist_nodo;
const int MAXN = 15;
const int INF = 1 << 30;
vector <pair <int, int> > g[MAXN];
int c, n, m, a, w, salida, dest, d[MAXN], p[MAXN];

void
limpiar() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }    
}

void
leerGrafo() {
    for(int i = 1; i <= n; i++) {
        cin >> m;
        while(m--) {
            cin >> a >> w;
            g[i].push_back(edge(a, w));
        }
    }
}

void
dijkstra(int nodo) {
    for(int i = 1; i <= n; i++) {
        d[i] = INF; p[i] = -1;   
    }
    priority_queue <dist_nodo, vector <dist_nodo>,
                    greater<dist_nodo> > q;
    d[nodo] = 0;
    q.push(dist_nodo(0, nodo));
    while(!q.empty()) {
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();  
        if (dist > d[cur]) continue;
        for(int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if(d[cur] + w_extra < d[next]) {
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_nodo(d[next], next));
            } 
        }
    }
}

vector <int> find_path (int t) {
    vector <int> path;
    int cur = t;
    while (cur != -1) {
        path.push_back(cur);
        cur = p[cur];   
    }
    reverse(path.begin(), path.end());
    return path;
}

int
main() {
    c = 1;
    while (cin >> n && n > 0) {
        limpiar();
        leerGrafo();
        cin >> salida >> dest;
        dijkstra(salida);
        printf("Case %d: Path =", c++);
        vector <int> path = find_path(dest);
        for(int i = 0; i < path.size(); i++) {
            cout << " " << path[i];
        }
        printf("; %d second delay\n", d[dest]);
    }   
    return 0;
}
