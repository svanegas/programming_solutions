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

typedef long long ll;
const int MAXN = 100005;
const ll INF = 1LL << 60;
typedef pair <int, ll> edge;
typedef pair <ll, int> dist_node;
vector <edge> g[MAXN];
ll d[MAXN];
bool prevArticle[MAXN], auxPrev[MAXN];
int a, n;

void
dijkstra(int s) {
  for (int i = 0; i <= n; i++) d[i] = INF;
  d[s] = 0LL;
  priority_queue <dist_node,
                  vector <dist_node>,
                  greater<dist_node> > q;
  q.push(dist_node(d[s], s));
  while (!q.empty()) {
    int cur = q.top().second;
    ll dist = q.top().first;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i].first;
      ll weight = g[cur][i].second;
      if (d[next] > d[cur] + weight) {
        d[next] = d[cur] + weight;
        q.push(dist_node(d[next], next)); 
      }
    } 
  }
}

int
main() {
  cin >> a >> n;
  for (int i = 0; i < a; ++i) {
    memset(auxPrev, false, sizeof(bool) * (n + 2));
    int x; cin >> x;
    vector <int> commArt, notCommArt;
    for (int j = 0; j < x; ++j) {
      int xi; cin >> xi;
      if (i == 0) notCommArt.push_back(xi); 
      else {
        if (prevArticle[xi]) commArt.push_back(xi);
        else notCommArt.push_back(xi);
      }
      auxPrev[xi] = true;
    }
    for (int it = 0; it < commArt.size(); ++it) {
      for (int it2 = 0; it2 < notCommArt.size(); ++it2) {
        int a = commArt[it], b = notCommArt[it2];
        g[a].push_back(edge(b, 1LL));
        g[b].push_back(edge(a, 1LL));
      }
    }
    for (int it = 1; it < notCommArt.size(); ++it) {
      int a = notCommArt[it], b = notCommArt[it - 1];
      g[a].push_back(edge(b, 0LL));
      g[b].push_back(edge(a, 0LL));
    }
    memcpy(prevArticle, auxPrev, sizeof(bool) * (n + 2));
  }
  dijkstra(1);
  int well = 1;
  ll sum = 0LL;
  ll maxi = 0LL;
  for (int i = 2; i <= n; ++i) {
    if (d[i] != INF) {
      sum += (d[i] + 1LL);
      well++;
      maxi = max(maxi, d[i] + 1LL);
    }
  }
  cout << well << " " << maxi << " " << sum << endl;
  return 0;
}
