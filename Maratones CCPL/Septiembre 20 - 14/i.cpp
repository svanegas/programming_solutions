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


class FenwickTree {
  vector <int> v;
  int maxSize;
  
public:
  FenwickTree(const vector <int> _v) : v(_v) {
    maxSize = v.size();
  }  
  
  void
  change(int where, int what) {
    for (where++; where < maxSize; where += where & -where) {
      v[where] = what; 
    }
  }
  
  int
  query(int where) {
    int prod = v[0];
    for (where++; where > 0; where -= where & -where) {
      prod *= v[where]; 
    } 
    return prod;
  }
  
  int
  query(int from, int to) {
    return query(to) * query(from - 1); 
  }
};

int n, k;

int
main() {
  while (cin >> n >> k) {
    vector <int> v;
    for (int i = 0; i < n; i++) {
      int xi;
      cin >> xi;
      v.push_back(xi);
    }
    FenwickTree tree(v);
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      cout << tree.query(a, b) << endl;
    }
  }
  return 0;
}
