//Santiago Vanegas Gil.
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
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 100005;
bool closed[MAXN];
int keyOpens[MAXN];
vector <int> g[MAXN];
bool seen[MAXN];
queue <int> keys;
int n, k, m;

void
dfs(int s) {
  seen[s] = true;
	if (keyOpens[s] != 0) {
    keys.push(keyOpens[s]);
    closed[keyOpens[s]] = false;
  }
	if (closed[s]) return;
	for (int i = 0; i < g[s].size(); ++i) {
	  int v = g[s][i];
	  if (!seen[v]) dfs(v);
  }
}

int
main() {
	while (cin >> n >> k >> m && n != -1) {
		memset(closed, false, sizeof closed);
		memset(keyOpens, 0, sizeof keyOpens);
		memset(seen, false, sizeof seen);
		keys = queue <int>();
		for (int i = 0; i <= n; ++i) {
      g[i].clear(); 
    }
		for (int i = 0; i < k; ++i) {
		  int a, b;
			cin >> a >> b;
			keyOpens[a] = b;
			closed[b] = true;
    }
		for (int i = 0; i < m; ++i) {
		  int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
    }
    keys.push(1);
    seen[1] = true;
    while (!seen[n] && !keys.empty()) {
	    int nextKey = keys.front(); keys.pop();
	    //IMPORTANT LINE:
      //Try the following case:
      //4 1 2
      //2 3
      //1 2
      //3 4
      //Answer is N
	    if (seen[nextKey]) dfs(nextKey);
    }
    if (seen[n]) cout << "Y" << endl;
    else cout << "N" << endl;
  }
	return 0;
}
