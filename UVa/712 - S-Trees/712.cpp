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

const int MAXN = 8;
int n, m;
int level[MAXN];
char vva[MAXN];
string tree;

char
solve() {
  int low = 0, high = (1 << n) - 1, mid;
  for (int i = 0; i < n; i++) {
    mid = low + (high - low) / 2;
    if (vva[level[i]-1] == '1') low = mid + 1;
    else high = mid;
  }
  return tree[high];
}

int
main() {
  int z = 1;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      getchar();
      scanf("x%d", &level[i]);
    }
    cin >> tree;
    cin >> m;
    string ans = "";
    while (m--) {
      string svva; cin >> svva;
      for (int i = 0; i < n; i++) {
        vva[i] = svva[i];
      }
      ans += solve();
    }
    printf("S-Tree #%d:\n", z++);
    cout << ans << endl << endl;
  }
  return 0;
}
