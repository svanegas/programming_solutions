using namespace std;

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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define PI acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n, a, b;

int main() {
  while (cin >> n && n) {
    a = b = 0;
    double bits = log(n) / log(2);
    int sz = ceil(log(n) / log(2));
    if (bits == floor(bits)) sz++;
    int cont = -1;
    for (int i = 0; i < sz; i++) {
      if (n & (1 << i)) {
        cont++;
        if (cont % 2 == 0) a |= (1 << i);
        else b |= (1 << i);
      }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
