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

const int MAXN = 32;
int t, n, k;
bitset <MAXN> num;

int
main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    num.reset();
    int power = (int) (pow(2.0, n * 1.0));
    for (int i = 1; i <= n; i++) {
      int step = power / ((int) (pow(2.0, i * 1.0)));
      num[n - i] = (k / step) % 2;
      if (i > 1 && ((k / (step << 1)) % 2)) num.flip(n - i);
    }
    cout << num.to_ulong() << endl;
  }
  return 0;
}
