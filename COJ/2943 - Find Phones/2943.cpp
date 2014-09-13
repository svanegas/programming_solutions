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

const int MAXN = 505;
vector <int> g[MAXN];
int tel[MAXN], p[MAXN], num[MAXN];
int n;

void
initialize() {
  for (int i = 0; i <= n; i++) {
    p[i] = i; 
    num[i] = -1;
  }
}

int
find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void
join(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return;
  p[a] = b;  
}

int
findNum(int group) {
  if (num[group] != -1) return num[group];
  for (int i = 1; i <= n; i++) {
    if (find(i) == group && tel[i] != 0) return tel[i]; 
  }
  return -1;
}

int
main() {
  cin >> n;
  initialize();
  for (int i = 1; i <= n; i++) cin >> tel[i];
  int a, b;
  while (cin >> a >> b) {
    join(a, b); 
  }
  for (int i = 1; i <= n; i++) {
    int group = find(i);
    num[group] = findNum(group);
    cout << num[group] << endl; 
  }
}
