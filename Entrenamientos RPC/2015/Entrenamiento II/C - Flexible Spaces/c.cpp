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

const int MAXN = 105;
int n, m;
vector <int> part;
bool can[MAXN];

void
solve() {
  memset(can, 0, sizeof can);
  for (int i = 0; i < part.size(); ++i) {
    for (int j = i + 1; j < part.size(); ++j) {
      can[part[j] - part[i]] = true;
    }
  }
}

int
main() {
  cin >> n >> m;
  part.push_back(0);
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    part.push_back(x);
  }
  part.push_back(n);
  solve();
  bool init = false;
  for (int i = 1; i <= n; ++i) {
    if (can[i]) {
      if (init) cout << " ";
      cout << i;
      init = true;
    }
  }
  cout << endl;
  return 0;
}

