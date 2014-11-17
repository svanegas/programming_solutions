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

int
main() {
  int xi;
  bitset <5> conn1, conn2;
  while (cin >> xi) {
    conn1[0] = xi;
    for (int i = 1; i < 5; ++i) {
      cin >> xi; conn1[i] = xi;
    }
    for (int i = 0; i < 5; ++i) {
      cin >> xi; conn2[i] = xi; 
    }
    if ((conn1 ^= conn2).count() == 5) cout << "Y" << endl;
    else cout << "N" << endl;
  }
  return 0;
}
