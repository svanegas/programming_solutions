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

const int MAXN = 22;
int n, m, c, z, maxi;
int consum[MAXN];
bool state[MAXN];

int
main() {
  z = 1;
  while (cin >> n >> m >> c && (n || m || c)) {
    memset(state, false, sizeof state);
    maxi = -1;
    for (int i = 1; i <= n; i++) cin >> consum[i];
    
    bool blown = false;
    int elect = 0;
    for (int i = 0; i < m; i++) {
      int xi; cin >> xi;
      state[xi] = true - state[xi];
      elect += (consum[xi] * (state[xi] ? 1 : -1));
      blown |= (elect > c);
      maxi = max(maxi, elect);
    }
    
    printf("Sequence %d\n", z++);
    if (blown) puts("Fuse was blown.\n");
    else {
      puts("Fuse was not blown.");
      printf("Maximal power consumption was %d amperes.\n\n", maxi);
    }
  }
  return 0;
}
