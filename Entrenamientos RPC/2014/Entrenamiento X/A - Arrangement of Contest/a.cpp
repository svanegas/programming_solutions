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

int n;

int
main() {
  cin >> n;
  int mask = 0;
  string line;
  getline(cin, line);
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    if (line.size() == 0) continue;
    int starts = line[0] - 'A';
    mask |= (1 << starts);
  }
  int i;
  for (i = 0; i < 26; ++i) {
    if (!(mask & (1 << i))) break;
  }
  cout << i << endl;
  return 0;
}
