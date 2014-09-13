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

typedef long long ll;
const int MAXN = 1005;
int n, m;
ll d[MAXN];

int
main() {
  memset(d, 0, sizeof d);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
     int a, b;
     cin >> a >> b;
     d[a]++;
     d[b]++;
  }
  cout << d[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << d[i];
  }
  cout << endl;
  return 0;
}
