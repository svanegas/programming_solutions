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

const int MAXN = 455;
vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
int scc[MAXN];
long long precio[MAXN];
bool seen[MAXN];
map <int, long long> tot;

void
dfs1(int u) {
    seen[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!seen[v]) dfs1(v);   
    }
    topo_sort.push_back(u);
}

void
dfs2(int u, int comp) {
    scc[u] = comp;
    for (int i = 0; i < grev[u].size(); i++) {
        int v = grev[u][i];
        if (scc[v] == -1) dfs2(v, comp);   
    }   
}

int
main() {
    int n, m;
    while (cin >> n >> m) {
        //Limpiar las variables entre caso y caso
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            grev[i].clear();
            topo_sort.clear();
            scc[i] = -1;
            seen[i] = false;
            if (i != n)
            cin >> precio[i];
            tot.clear();
        }
        
        //Crear el grafo y el reversado
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; 
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
            grev[v].push_back(u);
            grev[u].push_back(v);
            //Si no funciona agregar acá arista de ida
        }
        
        //Llamar el primer dfs
        for (int i = 0; i < n; i++) {
            if (!seen[i]) dfs1(i);   
        }
        reverse(topo_sort.begin(), topo_sort.end());
        
        //Llamar el segundo dfs
        int comp = 0;
        for (int i = 0; i < n; i++) {
            int u = topo_sort[i];
            if (scc[u] == -1) dfs2(u, comp++);   
        }
        
        //Sumar los pesos de las componentes
        for (int i = 0; i < n; i++) {
            int cI = scc[i];
            tot[1] += precio[i];   
        }
        
        //Decimos el mapa que tenga más valor
        long long maxi = 0;
        map <int, long long> :: iterator it;
        for (it = tot.begin(); it != tot.end(); it++) {
            maxi = max(maxi, it->second);
        }
        cout << maxi << endl;
    }
	return 0;
}
