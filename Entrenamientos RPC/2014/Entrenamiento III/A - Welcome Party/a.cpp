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

//user: eafit123
//pass: sandiego123

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 26 + 26 + 5; 
vector <int> g[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int prev[MAXN];
int n, t;

void 
connect(int i, int j) {
    printf("Conecto %d con %d\n", i, j);
    g[i].push_back(j);
    g[j].push_back(i);
    c[i][j] = 1;
    //c[i][j] += cap;    
    //c[j][i] += cap;
}

int
maxflow(int s, int t) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = 0;   
        }   
    }
    int flow = 0;
    while (true) {
        for (int i = 0; i <= n; i++) prev[i] = -1;
        queue <int> q;
        q.push(s);
        prev[s] = -2;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (prev[v] == -1 and c[u][v] - f[u][v] > 0) {
                    q.push(v);
                    prev[v] = u;   
                }   
            }   
        }
        if (prev[t] == -1) break;
        int extra = 1 << 30;
        int end = t;
        while (end != s) {
            int start = prev[end];
            extra = min(extra, c[start][end] - f[start][end]);
            end = start;   
        }
        end = t;
        while (end != s) {
            int start = prev[end];
            f[start][end] += extra;
            f[end][start] = -f[start][end];
            end = start;   
        }
        flow += extra;
    }
    return flow;
}

void
limpiar() {
    for (int i = 0; i < MAXN; i++) {
        c[i][i] = 0;
        g[i].clear(); 
    }
}

int
main() {
    while (cin >> t && t) {
        limpiar();
        while (t--) {
            string nombre, apellido;
            cin >> nombre >> apellido;
            if (apellido[0] == 'S' || apellido[0] == 'T' || 
                apellido[0] == 'U' || apellido[0] == 'V' ||
                apellido[0] == 'W' || apellido[0] == 'X' ||
                apellido[0] == 'Y' || apellido[0] == 'Z') continue;
               
            int nodoN = nombre[0] - 'A' + 1;
            int nodoA = apellido[0] - 'A' + 27;
            connect(nodoN, nodoA); //Conectar nombre con apellido
            connect(0, nodoN); //Conectar inicial con nombre
            connect(nodoA, 53); //Conectar apellido con final
        }
        n = 55;
        cout << maxflow(0, 53) << endl;
    }
	return 0;
}
