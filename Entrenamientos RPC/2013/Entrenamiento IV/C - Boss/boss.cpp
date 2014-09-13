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

const int MAXN = 505;
const int INF = 1 << 30;
int n, m, q;
int age[MAXN];
int color[MAXN];
int donde[MAXN];
map <int, int> lugar;
vector <int> g[MAXN];
enum {WHITE, GRAY, BLACK};
int menor;

void
dfs(int u) {
    color[u] = GRAY;
    //printf("Hago dfs con %d\n", u);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        //printf("Voy hacia el %d\n", v);
        if (color[v] == WHITE) {
            //printf("Menor estaba en %d evalúo con %d", menor, age[lugar[v]]);
            menor = min(menor, age[lugar[v]]);
            //printf(" y quedó en %d\n", menor);
            dfs(v);
        }   
    }
    color[u] = BLACK;    
}

int
call_dfs(int nodo) {
    for (int u = 1; u <= n; u++) color[u] = WHITE;
    dfs(nodo);
    return menor;
}

int
main() {
    while (cin >> n >> m >> q) {
        for (int i = 1; i <= n; i++) {
            cin >> age[i];
            lugar[i] = i;
            donde[i] = i;
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[y].push_back(x);
        }
        for (int i = 0; i < q; i++) {
            char t; cin >> t;
            if (t == 'T') {
                int a, b; cin >> a >> b;
                swap(lugar[donde[a]], lugar[donde[b]]);
                int aux = donde[a];
                donde[a] = donde[b];
                donde[b] = aux; 
            }
            else {
                menor = INF;
                int e; cin >> e;
                if (call_dfs(donde[e]) == INF) cout << '*' << endl;
                else cout << menor << endl;   
            }
        }
    }
    return 0;
}
