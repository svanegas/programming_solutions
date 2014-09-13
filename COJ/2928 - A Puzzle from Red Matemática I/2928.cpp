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
 
int d, k;

int
main() {
  while (cin >> d >> k && d && k) {
    switch (d) {
      case 1:
        cout << ((k / 9) * 81) + ((k % 9) * (k % 9)) << endl;
        break;
      case 2:
        if (k == 1) cout << 4 << endl;
        else if (k == 2) cout << 16 << endl;
        else if (k % 3 == 0) cout << (27 * (k / 3)) << endl;
        else if ((k - 1) % 9 == 0) cout << (4 + (81 * ((k - 1) / 9))) << endl;
        else if ((k + 2) % 9 == 0) cout << (-20 + (81 * ((k + 2) / 9))) << endl; 
        else if ((k + 5) % 9 == 0) cout << (-44 + (81 * ((k + 5) / 9))) << endl;
        else if ((k - 2) % 9 == 0) cout << (16 + (81 * ((k - 2) / 9))) << endl;
        else if ((k + 1) % 9 == 0) cout << (-14 + (81 * ((k + 1) / 9))) << endl;
        else if ((k + 4) % 9 == 0) cout << (-35 + (81 * ((k + 4) / 9))) << endl;
        break; 
      case 3:
        cout << (9 * k) << endl;
        break;
      case 4:
        if (k == 1) cout << 7 << endl;
        else if (k == 2) cout << 19 << endl;
        else if (k % 3 == 0) cout << (27 * (k / 3)) << endl;
        else if ((k - 1) % 9 == 0) cout << ((4 + (81 * ((k - 1) / 9))) + 3) << endl;
        else if ((k + 2) % 9 == 0) cout << ((-20 + (81 * ((k + 2) / 9))) + 3) << endl; 
        else if ((k + 5) % 9 == 0) cout << ((-44 + (81 * ((k + 5) / 9))) + 3) << endl;
        else if ((k - 2) % 9 == 0) cout << ((16 + (81 * ((k - 2) / 9))) + 3) << endl;
        else if ((k + 1) % 9 == 0) cout << ((-14 + (81 * ((k + 1) / 9))) + 3) << endl;
        else if ((k + 4) % 9 == 0) cout << ((-35 + (81 * ((k + 4) / 9))) + 3) << endl;
        break;
      case 5:
        if (k % 3 == 0) {
          if (k % 9 == 0) cout << (9 * (k / 3)) << endl;
          else cout << (9 * ((k / 3) - 1)) << endl;
        }
        else if ((k - 2) % 9 == 0) cout << (10 + (81 * ((k - 2) / 9))) << endl;
        else if ((k + 1) % 9 == 0) cout << (-11 + (81 * ((k + 1) / 9))) << endl;
        else if ((k + 4) % 9 == 0) cout << (-41 + (81 * ((k + 4) / 9))) << endl;
        else if ((k - 1) % 9 == 0) cout << (7 + (81 * ((k - 1) / 9))) << endl;
        else if ((k + 2) % 9 == 0) cout << (-26 + (81 * ((k + 2) / 9))) << endl;
        else if ((k + 5) % 9 == 0) cout << (-50 + (81 * ((k + 5) / 9))) << endl;
        break;
      case 6:
        cout << (9 * k) << endl;
        break;
      case 7:
        if (k == 1) cout << 13 << endl;
        else if (k == 2) cout << 25 << endl;
        else if (k == 4) cout << 24 << endl;
        else if (k % 3 == 0) cout << (27 * (k / 3)) << endl;
        else if ((k - 4) % 9 == 0) cout << (37 + (81 * ((k - 4) / 9))) << endl;
        else if ((k - 1) % 9 == 0) cout << (13 + (81 * ((k - 1) / 9))) << endl;
        else if ((k + 2) % 9 == 0) cout << (-20 + (81 * ((k + 2) / 9))) << endl;
        else if ((k - 2) % 9 == 0) cout << (25 + (81 * ((k - 2) / 9))) << endl;
        else if ((k + 1) % 9 == 0) cout << (-5 + (81 * ((k + 1) / 9))) << endl;
        else if ((k + 4) % 9 == 0) cout << (-35 + (81 * ((k + 4) / 9))) << endl;
        break;
      case 8:
        if (k == 1) cout << 10 << endl;
        else if (k == 2) cout << 22 << endl;
        else if (k % 3 == 0) {
          if ((k / 3) % 3 == 0) cout << (9 * ((k / 3) - 1)) << endl;
          else cout << (9 * (k / 3)) << endl;
        }
        else if ((k - 1) % 9 == 0) cout << (10 + (81 * ((k - 1) / 9))) << endl;
        else if ((k + 2) % 9 == 0) cout << (-14 + (81 * ((k + 2) / 9))) << endl;
        else if ((k + 5) % 9 == 0) cout << (-29 + (81 * ((k + 5) / 9))) << endl;
        else if ((k - 2) % 9 == 0) cout << (22 + (81 * ((k - 2) / 9))) << endl;
        else if ((k + 1) % 9 == 0) cout << (-8 + (81 * ((k + 1) / 9))) << endl;
        else if ((k + 4) % 9 == 0) cout << (-38 + (81 * ((k + 4) / 9))) << endl;
        break;
      case 9:
        cout << (9 * k) << endl;
        break;
    } 
  }
  return 0;
}
