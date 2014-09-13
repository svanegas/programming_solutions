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

int n, k;
vector <int> comp;

int
main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    comp.push_back(xi);
  }
  sort(comp.rbegin(), comp.rend());
  cout << comp[k-1] << endl;
  return 0;
}
