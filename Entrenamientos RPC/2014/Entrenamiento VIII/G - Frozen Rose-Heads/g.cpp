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

const int MAXN = 1005;
const int INF = 1 << 30;
typedef pair <int, int> edge;
bool seen[MAXN];
vector <edge> g[MAXN];

int n, s;

int
dfs(int u, int w) {
  seen[u] = true;
  int sum = 0;
  bool sink = true;
	for (int i = 0; i < g[u].size(); i++) {
    int next = g[u][i].first;
    int weight = g[u][i].second;
		if (!seen[next]) {
      sink = false;
			sum += dfs(next, weight);
		}
	}
  if (sink) return w;
	else if (w < sum) return w;
	else return sum;
}

int
main() {
  //while (cin >> n >> s) {
  while (scanf("%d %d", &n, &s) != EOF) {
    for (int i = 0; i <= n; i++) {
      g[i].clear();
      seen[i] = false;
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b, w;
      //cin >> a >> b >> w;
      scanf("%d %d %d", &a, &b, &w);
      g[a].push_back(edge(b, w));
      g[b].push_back(edge(a, w));
    }
    //cout << dfs(s, INF) << endl;
    printf("%d\n", dfs(s, INF));
  }
  return 0;
}
