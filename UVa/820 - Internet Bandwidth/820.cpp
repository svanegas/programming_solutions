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

const int MAXN = 105;
const int INF = 1 << 30;
vector<int> g[MAXN];
int f[MAXN][MAXN];
int c[MAXN][MAXN];
int prev[MAXN];
int s, t;

void
leerRed(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            c[i][j] = 0;   
        }
        g[i].clear();   
    }
    int ca;
    cin >> s >> t >> ca;
    while (ca--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(b);
        g[b].push_back(a);
        c[a][b] += w;
        c[b][a] += w;
        //printf("Agrego de %d a %d - %d\n", a, b, w);
    }
    //puts("Paso relas");
}

int
maxFlow(int n) {
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
                if (prev[v] == -1 && c[u][v] - f[u][v] > 0) {
                    q.push(v);
                    prev[v] = u;
                }
            }   
        }
        //puts("E");
        if (prev[t] == -1) break;
        
        int extra = INF;
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

int
main() {
    int z, n;
    z = 1;
    while (cin >> n && n != 0) {
        leerRed(n);
        printf("Network %d\n", z++);
        printf("The bandwidth is %d.\n\n", maxFlow(n));
    }
    return 0;
}
