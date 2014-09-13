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

int n, v;

int
main() {
  cin >> n >> v;
  vector <int> can;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    bool read = true;
    for (int j = 0; j < x; j++) {
      int vi; cin >> vi;
      if (vi < v && read) {
        can.push_back(i);
        read = false; 
      }
    }
  }
  cout << can.size() << endl;
  if (can.size() > 0) cout << can[0];
  for (int i = 1; i < can.size(); i++) {
    cout << " " << can[i]; 
  }
  puts("");
  return 0;
}
