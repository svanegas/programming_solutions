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

void
injerto(int n) {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            c[i][j] = 0;
        }
        g[i].clear();
    }
    int ca = n - 2;
    int id, cost;
    g[1].push_back(51);
    g[51].push_back(1);
    c[1][51] += INF;
    c[51][1] += INF;
    g[n].push_back(n+50);
    g[n+50].push_back(n);
    c[n][n+50] += INF;
    c[n+50][n] += INF;
    while (ca--) {
        cin >> id >> cost;
        g[id].push_back((id+50));
        g[id+50].push_back(id);
        c[id][(id+50)] += cost;
        c[id+50][id] += cost;
    }
}

void
leerRed(int w, int m) {
    int ca = w;
    while (ca--) {
        int a, b, costo;
        cin >> a >> b >> costo;
        g[a+50].push_back(b);
        g[b].push_back(a+50);
        c[a+50][b] += costo;
        
        g[b+50].push_back(a);
        g[a].push_back(b+50);
        c[b+50][a] += costo;
    }
}

int
maxFlow(int s, int t, int n) {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            f[i][j] = 0;  
        }   
    }
    int flow = 0;
    while (true) {
        for (int i = 0; i <= n; i++) {
            prev[i] = -1;
            prev[i+50] = -1;
        }
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
    int m, w;
    while (cin >> m >> w && (m || w)) {
        injerto(m);
        leerRed(w, m);
        cout << maxFlow(1, m, m) << endl;
    }
    return 0;
}
