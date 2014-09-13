#include <iostream>
#include <algorithm>
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
#include <bitset>

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef pair <int, int> edge;
const int MAXN = 1005;
int n, m, dfsNumberCounter, dfsRoot, rootChildren;
int dfs_low[MAXN], dfs_num[MAXN], dfs_parent[MAXN], articulation_vertex[MAXN];
vector <int> g[MAXN];
set <edge> puentecitos;

void
articulationBridge (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < g[u].size(); j++) {
        int v = g[u][j];
        if (dfs_num[v] == -1) { //Unvisited
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationBridge(v);
            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v] > dfs_num[u])
                //printf("Puente (%d, %d)\n", u, v);
                puentecitos.insert(edge(min(u, v), max(u, v)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int
main() {
    while (cin >> n >> m && (n || m)) {
        puentecitos.clear();
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            dfs_num[i] = -1;
            dfs_low[i] = 0;
            dfs_parent[i] = 0;
            articulation_vertex[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfsNumberCounter = 0;
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == -1) {
                dfsRoot = i;
                rootChildren = 0;
                articulationBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        cout << puentecitos.size();
        set <edge> :: iterator it;
        for (it = puentecitos.begin(); it != puentecitos.end(); it++) {
            edge impr = *it;
            cout << " " << impr.first << " " << impr.second;
        }
        cout << endl;
    }
    return 0;
}
