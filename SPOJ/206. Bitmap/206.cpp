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

typedef pair <int, int> indices;
const int INF = 1 << 30;
const int MAXN = 1005;
int c, n, m, d[MAXN][MAXN];
vector <int> g[MAXN];
queue <indices> cola;
bool visit[MAXN];

void
limpiar() {
    for(int i = 0; i < MAXN; i++) {
        visit[i] = false;
    }
}

vector <indices>
hijos(indices nodo) {
    vector <indices> ret;
    int posI = nodo.first;
    int posJ = nodo.second;
    if (posI - 1 >= 0) ret.push_back(indices(posI-1, posJ));
    if (posI + 1 < n) ret.push_back(indices(posI+1, posJ));
    if (posJ - 1 >= 0) ret.push_back(indices(posI, posJ-1));
    if (posJ + 1 < m) ret.push_back(indices(posI, posJ+1));
    return ret;
}

void
bfs() {
    while (!cola.empty()) {
        indices blanco = cola.front(); cola.pop();
        int curI = blanco.first;
        int curJ = blanco.second;
        vector <indices> conex = hijos(blanco);
        for (int i = 0; i < conex.size(); i++) {
            int nextI = conex[i].first;
            int nextJ = conex[i].second;
            if (d[curI][curJ]+1 < d[nextI][nextJ]) {
                d[nextI][nextJ] = d[curI][curJ]+1;
                indices sig(nextI, nextJ);
                cola.push(sig);
            }  
        }
    }  
}

int
main() {
    cin >> c;
    while (c--) {
        cin >> n >> m;
        limpiar();
        for (int i = 0; i < n; i++) {
            vector <int> temp;
            string linea;
            cin >> linea;
            for (int j = 0; j < m; j++) {
                d[i][j] = INF;
                int x = linea[j]-48;
                if (x == 1) {
                    indices blanco(i, j);
                    cola.push(blanco);
                    d[i][j] = 0;
                }
                temp.push_back(x);
            }
            g[i] = temp;
        }
        bfs();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) {
                    if (j != m - 1) printf("%d ", d[i][j]);
                    else printf("%d", d[i][j]);
                }
                else {
                    if (j != m - 1) printf("0 ");
                    else printf("0");
                }
            }
            puts("");  
        }
    }
    return 0;
}

