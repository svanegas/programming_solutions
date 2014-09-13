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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 1024;
int t, n, m;
bitset <MAXN + 5> ppl;

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ppl.set();
    while (m--) {
      int xi; cin >> xi; xi--;
      ppl[xi] = 0;
    }
    int ans = 0;
    n = (int) (pow(2.0, n * 1.0));
    while (n) {
      int index = 0;
      for (int i = 1; i < n; i += 2) {
        ans += (ppl[i] ^ ppl[i-1]);
        ppl[index++] = ppl[i] || ppl[i-1];
      }
      n >>= 1;
    }
    cout << ans << endl;
  }
  return 0;
}
