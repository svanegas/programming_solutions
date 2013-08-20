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

typedef pair <int, int> edge; //Primero nodo al cual va y con que peso
typedef pair <int, int> dist_node; //Primero peso y despues nodo (Dijkstra)
typedef pair <int, int> pareja; //Nodo salida y llegada de una arista
const int MAXN = 505;
const int INF = 1 << 30;
vector<edge> g[MAXN];
int d[MAXN];
int p[MAXN];
int source, dest, minim;
priority_queue < int, vector <int>,
                    greater<int> > ldist;
vector <vector <int> > caminosCortos;
vector <pareja> elim; //Lista de aristas a elminiar con camino corto

vector <int>
hallarCamino(int nodo, int padre) {
    vector <int> trayec;
    trayec.push_back(nodo);
    trayec.push_back(padre);
    while (padre != source) {
        padre = p[padre];
        trayec.push_back(padre);
    }
    return trayec;
}

void
limpiar(int n) {
    for(int l = 0; l <= n; l++) {
        g[l].clear();
        d[l] = INF;
        p[l] = -1;
    }
    caminosCortos.clear();
    elim.clear();
}

void
dijkstra(int s){
    priority_queue < dist_node, vector <dist_node>,
                    greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if (next == dest) {
                ldist.push(d[cur] + w_extra); 
            }
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));
            }
        }
    }
}

void
dijkstra2(int s){
    priority_queue < dist_node, vector <dist_node>,
                    greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        int tempD = d[cur];
        int tempP = p[cur];
        if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if (next == dest && d[cur] + w_extra == minim) {
                caminosCortos.push_back(hallarCamino(next, cur));
            }
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));
            }
        }
        d[cur] = tempD;
    }
}


int
main() {
    int n, m;
    while (cin >> n >> m && (n || m)) {
        cin >> source >> dest;
        limpiar(n);
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            g[u].push_back(edge(v,p));
        }
        dijkstra(source);
        minim = d[dest];
        if (minim != INF) {
            for(int l = 0; l <= n; l++) {
                d[l] = INF;
                p[l] = -1;
            }
            caminosCortos.clear();
            dijkstra2(source);
        }
        else {
            puts("-1");
            continue;
        }
        
        for (int i = 0; i < caminosCortos.size(); i++) {
            vector <int> cam = caminosCortos[i];
            reverse(cam.begin(), cam.end());
            for (int j = 0; j < cam.size() - 1; j++) {
                elim.push_back(pareja(cam[j], cam[j+1]));
            }
        }
        
        
        for (int i = 0; i < elim.size(); i++) {
            int u = elim[i].first;
            int v = elim[i].second;
            for (int j = 0; j < g[u].size(); j++) {
                if (g[u][j].first == v) {
                    g[u].erase(g[u].begin()+j);   
                }
            }   
        }
        
        for(int l = 0; l <= n; l++) {
            d[l] = INF;
            p[l] = -1;
        }
        
        dijkstra(source);
        
        if (d[dest] == INF) puts("-1");
        else printf("%d\n", d[dest]);
    }
    return 0;
}

