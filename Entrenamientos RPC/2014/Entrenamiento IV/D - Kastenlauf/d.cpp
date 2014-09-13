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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef pair <int, int> coord;
const int MAXN = 105;
int t, n;
vector <coord> points;
vector <int> g[MAXN];
bool visit[MAXN];

bool
can(coord p1, coord p2) {
  return (abs(p2.first - p1.first) + abs(p2.second - p1.second)) <= 1000;
}

void
bfs(int s) {
  queue <int> q;
  q.push(s);
  visit[s] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];
      if (!visit[next]) {
        visit[next] = true;
        q.push(next); 
      } 
    } 
  }
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> n;
    points.clear();
    for (int i = 0; i <= n + 1; i++) {
      g[i].clear();
      visit[i] = false;
    }
    int x1, y1;
    for (int i = 0; i <= n + 1; i++) {
      cin >> x1 >> y1;
      points.push_back(coord(x1, y1));
    }
    for (int i = 0; i <= n + 1; i++) {
      for (int j = i + 1; j <= n + 1; j++) {
        if (can(points[i], points[j])) {
          g[i].push_back(j);
          g[j].push_back(i);
        } 
      }
    }
    bfs(0);
    if (!visit[n+1]) puts("sad");
    else puts("happy");
  }
  return 0;
}
