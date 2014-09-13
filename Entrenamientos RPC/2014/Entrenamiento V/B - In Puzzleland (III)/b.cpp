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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 28;
int t, n, m;
vector <int> g[MAXN];
int ini, fin;
string ans;

int
readNode() {
  char x; cin >> x;
  return (int)(x - 'A');  
}

bool
findPath(int s, string path, int seen) {
  //If i already done the path...
  if (path.size() == n - 1) {
    for (int i = 0; i < g[s].size(); i++) {
      if (g[s][i] == fin) {
        ans = path;
        ans += (char)(fin + 'A');
        return true; 
      }
    }
    return false; 
  }
  for (int i = 0; i < g[s].size(); i++) {
    //If I haven't visited it.
    if (!(seen & (1 << g[s][i]))) {
      int nextSeen = seen | (1 << g[s][i]);
      string nextPath = path;
      nextPath += (char)(g[s][i] + 'A');
      if (findPath(g[s][i], nextPath, nextSeen)) {
        return true;
      }
    }
  }
  return false;
}

int
main() {
  cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n >> m;
    
    //Clear all alphabet letters
    for (int i = 0; i < MAXN; i++) g[i].clear();
    
    ini = readNode();
    for (int i = 1; i < n - 1; i++) readNode();
    fin = readNode();
    
    for (int i = 0; i < m; i++) {
      int a, b;
      a = readNode();
      b = readNode();
      g[a].push_back(b);
      g[b].push_back(a); 
    }
    
    for (int i = 0; i < MAXN; i++) sort(g[i].begin(), g[i].end()); 
    
    int seen = 1 << ini;
    seen |= (1 << fin);
    string path = "";
    path += (char)(ini + 'A');
    if (findPath(ini, path, seen)) cout << "Case " << c << ": " << ans << endl;
    else cout << "Case " << c << ": impossible" << endl;
  }
  return 0;
}
