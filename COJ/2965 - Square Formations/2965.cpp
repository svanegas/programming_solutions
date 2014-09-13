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

vector <int> squares;
int t, z = 1;

void
build() {
  for (int i = 1; i <= 1001; i++) squares.push_back(i * i);
}

int
main() {
  build();
  cin >> t;
  while (t--) {
    int k; cin >> k;
    for (int i = 0; i < squares.size(); i++) {
      int n = squares[i] - k, soldiers = (n / 2) + k;
      if (n <= 0 || n % 2 == 1) continue;
      int sq = (int) sqrt(soldiers);
      if (sq * sq == soldiers) {
        printf("Case %d: %d\n", z++, n);
        break; 
      }
    }
  }
  return 0;
}
