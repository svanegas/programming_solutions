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

const int MAXN = 1005;
int t[MAXN];
int color[MAXN];
map <string, int> m;
map <int, string> m2;
int n, eme, maxi, nombre;
vector <int> g[MAXN];
priority_queue <string, vector<string>, greater<string> > q;
enum {WHITE, GRAY, BLACK};

void
dfs(int u) {
    color[u] = GRAY;
    if (t[u] > maxi) {
        maxi = t[u];
        nombre = u;   
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (color[v] == WHITE) dfs(v);
    }
    color[u] = BLACK; 
}

void
call_dfs() {
    for (int i = 0; i < n; i++) color[i] = WHITE;
    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            maxi = -1;
            dfs(i);
            q.push(m2[nombre]);
        }
    }
}

int
main() {
    while (cin >> n >> eme && n) {
        for (int i = 0; i <= n; i++) {
            g[i].clear();   
        }
        q = priority_queue <string, vector<string>, greater<string> >();
        m.clear();
        m2.clear();
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            m[s] = i;
            m2[i] = s;
            cin >> t[i];
        }
        for (int i = 0; i < eme; i++) {
            string a, b; cin >> a >> b;
            g[m[a]].push_back(m[b]);
            g[m[b]].push_back(m[a]);
        }
        
        call_dfs();
        
        while (!q.empty()) {
            cout << q.top() << endl;
            q.pop();   
        }
    }
    return 0;
}
