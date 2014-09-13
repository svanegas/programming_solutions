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


double prob[7];
int pizza[7];
double tot;

int
main() {
  while (cin >> pizza[0]) {
    tot = 0.0;
    prob[0] = 0.0;
    for (int i = 1; i < 7; i++) {
      cin >> pizza[i]; 
      prob[i] = 0.0;
    }
    for (int i = 0; i < 7; i++) {
      if (pizza[i]) {
        prob[(i + 1) % 7] += 0.6;
        prob[(i + 2) % 7] += 0.4;
        tot++;
      }
    }
    for (int i = 0; i < 7; i++) {
      if (tot != 0.0) prob[i] /= tot;
      cout << prob[i];
      if (i == 6) cout << endl;
      else cout << " "; 
    }
  }
  return 0;
}
