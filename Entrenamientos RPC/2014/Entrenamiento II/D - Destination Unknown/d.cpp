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

#define D(x) //cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 2005;
const int INF = 1 << 30;
typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
int cases, n, m, t, s, v1, v2;
int d[MAXN];
int p[MAXN];
vector <edge> g[MAXN];
vector <int> possible;
vector <int> repe[MAXN];

void
dijkstra(int s) {
    D(n);
    D(s);
    for (int i = 0; i <= n; i++) {
        d[i] = INF; p[i] = -1;   
    }
    priority_queue <dist_node, vector <dist_node>, greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()) {
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        D(dist);
        if (dist > d[cur]) continue;
        D(cur);
        D(g[cur].size());
        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            D(next);
            D(w_extra);
            if (d[cur] + w_extra == d[next]) {
                repe[next].push_back(cur);   
            }
            if (d[cur] + w_extra < d[next]) {
                repe[next].clear();
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));   
            }
        }   
    }
}

vector <int>
find_path (int nodo) {
    vector <int> path;
    int cur = nodo;
    while (cur != -1) {
        path.push_back(cur);
        cur = p[cur];   
    }
    reverse(path.begin(), path.end());
    return path;
}

int
main() {
    cin >> cases;
    while (cases--) {
        cin >> n >> m >> t;
        cin >> s >> v1 >> v2;
        s--; v1--; v2--;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            repe[i].clear();
        }
        possible.clear();
        while (m--) {
            int a, b;
            int peso;
            cin >> a >> b >> peso;
            a--; b--;
            g[a].push_back(edge(b, peso));
            g[b].push_back(edge(a, peso));
        }
        while (t--) {
            int xt; cin >> xt;
            xt--;
            possible.push_back(xt);
        }
        sort(possible.begin(), possible.end());
        dijkstra(s);
        
        for (int i = 0; i < possible.size(); i++) {
            vector <int> otrosPos;
            vector <int> path = find_path(possible[i]);
            bool isV1, isV2;
            isV1 = isV2 = false;
            for (int j = 0; j < path.size(); j++) {
                isV1 |= (path[j] == v1);
                isV2 |= (path[j] == v2);
                for (int otros = 0; otros < repe[path[j]].size(); otros++) {
                    vector <int> toditos = find_path(repe[path[j]][otros]);
                    otrosPos.insert(otrosPos.begin(), toditos.begin(), toditos.end());
                }
            }
            for (int j = 0; j < otrosPos.size(); j++) {
                isV1 |= (otrosPos[j] == v1);
                isV2 |= (otrosPos[j] == v2); 
            }
            if (isV1 && isV2) {
                cout << " " << (possible[i]+1);
            }
        }
        puts("");
    }
	return 0;
}
