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
const int INF = 1 << 30; //Infinito 2^30
vector<edge> g[MAXN]; //Lista de adyacencia para hacer el grafo
int d[MAXN]; //Arreglo para almacenar distancias
int p[MAXN]; //Arreglo para almacenar el predecesor
int source, dest, minim; //Enteros para almacenar nodo de inico, final y peso
                         //del camino más corto
vector <vector <int> > caminosCortos; //Para almacenar todos los caminos minimos
vector <pareja> elim; //Lista de aristas a elminiar con camino corto

vector <int> // Para hallar la secuencia de nodos que conforma un camino
             //Desde nodo, pasando por padre, hasta el inicio.
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

void //Limpia todo para nuevo caso de prueba
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
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));
            }
        }
    }
}

void //Modificación de condición
dijkstra2(int s){
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
            if (next == dest && d[cur] + w_extra == minim) { //Agregación.
                //Si encuentro un camino con el peso que hallé en el primer
                //dijkstra, lo guardo.
                caminosCortos.push_back(hallarCamino(next, cur));
            }
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
    int n, m;
    //while (cin >> n >> m && (n || m)) { //Leo n y m y que sean distintos de 0
    while (scanf("%d%d", &n, &m) && (n || m)) {
        //cin >> source >> dest; //Leo nodo inicio y final
        scanf("%d%d", &source, &dest);
        limpiar(n); //Limpio
        for (int i = 0; i < m; i++) { //Leo las aristas
            int u, v, p;
            //cin >> u >> v >> p;
            scanf("%d%d%d", &u, &v, &p);
            g[u].push_back(edge(v,p));
        }
        dijkstra(source); //Hago el primer dijkstra para hallar el peso minimo
        minim = d[dest]; //Almaceno ese peso minimo en minim
        if (minim != INF) { //Si es válido, continúo a hallar los otros caminos
                            // más cortos
            for(int l = 0; l <= n; l++) {
                d[l] = INF;
                p[l] = -1;
            }
            caminosCortos.clear();
            dijkstra2(source);
        }
        else { //Si no pongo -1 y continúo con el otro caso
            puts("-1");
            continue;
        } 
        
        //Preparo los caminos para eliminarlos
        for (int i = 0; i < caminosCortos.size(); i++) {
            vector <int> cam = caminosCortos[i];
            reverse(cam.begin(), cam.end());
            for (int j = 0; j < cam.size() - 1; j++) {
                int nodo = cam[j];
                //Los preparo para eliminar las parejas de nodos (Aristas)
                elim.push_back(pareja(cam[j], cam[j+1]));
            }
        }
        
        //Recorro el vecotr de eliminar y elimino
        for (int i = 0; i < elim.size(); i++) {
            int u = elim[i].first;
            int v = elim[i].second;
            for (int j = 0; j < g[u].size(); j++) {
                if (g[u][j].first == v) {
                    g[u].erase(g[u].begin()+j);
                    break;   
                }
            }   
        }
        
        //Limpio distancias para correr el nuevo dijkstra
        for(int l = 0; l <= n; l++) {
            d[l] = INF;
        }
        
        //Corro el nuevo dijkstra
        dijkstra(source);
        
        //SI hay un camino lo imprimo, de lo contrario -1
        if (d[dest] == INF) puts("-1");
        else printf("%d\n", d[dest]);
    }
    return 0;
}
