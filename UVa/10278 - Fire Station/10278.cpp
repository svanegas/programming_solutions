#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef pair <int, int> edge;
const int MAXN = 505;
const int INF = 1 << 30;
bool station[MAXN];
int dist_station[MAXN];
vector <edge> g[MAXN];
int d[MAXN];

void dijkstra(int s, int n){
    for (int i = 0; i <= n; ++i) d[i] = INF;
    
    priority_queue < edge, vector <edge>, greater<edge> > q;
    q.push(make_pair(0, s));
    d[s] = 0;
    while (!q.empty()){
        int cur = q.top().second;
        int dist = q.top().first;
        q.pop();
        if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                q.push(make_pair(d[next], next));
            }
        }
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--){
        int f, n;
        cin >> f >> n;
        for (int i = 0; i <= n; ++i){
            g[i].clear();
            station[i] = false;
            dist_station[i] = INF;
        }
        for (int i = 0; i < f; ++i){
            int place; cin >> place;
            station[place] = true;
        }
        string line;
        getline(cin, line);
        while (getline(cin, line)){
            if (line == "") break;
            stringstream ss(line);
            int u, v, w;
            ss >> u >> v >> w;
            g[u].push_back(edge(v, w));
            g[v].push_back(edge(u, w));
        }
        for (int i = 1; i <= n; ++i){
            if (station[i]){
                dijkstra(i, n);
                for (int j = 1; j <= n; ++j){
                    dist_station[j] = min(dist_station[j], d[j]);
                }
            }
        }
        int best_pos = 1;
        int best_dist = INF+1;
        for (int i = 1; i <= n; ++i){
            if (!station[i]){
                dijkstra(i, n);
                int max_dist = 0;
                for (int j = 1; j <= n; ++j){
                    int this_dist = min(dist_station[j], d[j]);
                    max_dist = max(max_dist, this_dist);
                }
                if (max_dist < best_dist){
                    best_dist = max_dist;
                    best_pos = i;
                }

            }
        }
        cout << best_pos << endl;
        if (cases) cout << endl;
    }
    return 0;
}
                    
                    
/*void
limpiar() {
    for(int i = 0; i <= n; i++) {
        fire[i] = false;
        g[i].clear();
    }
    mapa.clear();
    fireV.clear();
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

int
main() {
    cin >> c;
    //cout << INF << endl;
    while (c--) {
        cin >> f >> n;
        limpiar();
        for(int i = 0; i < f; i++) {
            int nodoF;
            cin >> nodoF;
            fire[nodoF] = true;
            fireV.push_back(nodoF);
        }
        getchar();
        while(getline(cin, tmp) && tmp.size() > 0) {
            stringstream ss(tmp);
            ss >> a >> b >> w;
            g[a].push_back(edge(b, w));
            if(a != b) g[b].push_back(edge(a, w));
        }
        
        tot = INF;
        for(int k = 1; k <= n; k++) {
            if(fire[k]) continue;
            //printf("Pongo fire a %d\n", k);
            fire[k] = true;
            fireV.push_back(k);
            int totAFire = 0;
            for(int i = 1; i <= n; i++) {
                if(fire[i]) continue;
                dijkstra(i);
                int minAFire = INF;
                for(int j = 0; j < fireV.size(); j++) {
                    int nodoFire = fireV[j];
                    //printf("La distancia de %d hasta %d es de %d\n",
                            //i, nodoFire, d[nodoFire]);
                    
                    minAFire = min(minAFire, d[nodoFire]);
                }
                //printf("Para %d queda mas cercano %d\n", i, minAFire);
                totAFire += minAFire;
                //printf("totAFire queda en %d\n", totAFire);
            }
            tot = min(tot, totAFire);
            mapa[totAFire] = k;
            fire[k] = false;
            fireV.pop_back();
        }
        cout << mapa[tot];
        if(c) printf("\n\n");
    }
    return 0;
}*/
