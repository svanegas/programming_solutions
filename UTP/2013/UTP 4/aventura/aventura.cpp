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
typedef pair <int, int> edge;
typedef pair <int, int> dist_node;
vector<edge> g[MAXN];
map <int, int> fin;
map <int, int> ini;
map <int, int> puente;


int d[MAXN];
int p[MAXN];

void
limpiar(int n) {
    for(int l = 0; l <= n; l++) {
        g[l].clear();
        d[l] = INF;
        p[l] = -1;
    }
}

void
dijkstra(int s) {
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
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));
            }
        }
    }    
}

int
main() {
    int c; cin >> c;
    while (c--) {
        int maxPags = 0;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            maxPags = max(maxPags, b);
            ini[i] = a;
            fin[i] = b;
            g[a].push_back(edge(b, (b-a)));
            puente[i] = p;
        }
        for (int i = 1; i < n; i++) {
            int auxP = puente[i];
            int final = fin[auxP];
            int inicial = ini[i];
            g[final].push_back(edge(inicial, 1));
        }
        puts("Constriido");
        int q; cin >> q;
        while (q--) {
            int prueba;
            cin >> prueba;
            int hMin, hMax;
            //cin >> hMin >> hMax;
            limpiar(maxPags);
            dijkstra(prueba);
            int minim = INF;
            for (int i = 1; i <= maxPags; i++) {
                if (i == prueba) continue;
                printf("d[%d] = %d\n", i, d[i]);
                if (d[i] != INF && g[i].size() == 0) {
                    minim = min(minim, d[i]);
                    printf("Hacia nodo: %d\n", i);
                }
            }
            printf("EL minimo es: %d\n", minim);
        }
        
    }
    return 0;
}
