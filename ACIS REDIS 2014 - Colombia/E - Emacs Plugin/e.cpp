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

int cas, ini;
string t, p;

bool
kmp(const string &needle) {
  int m = needle.size();
  vector <int> border(m);
  border[0] = 0;
  
  for (int i = 1; i < m; i++) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]])
      border[i] = border[border[i] - 1];
    if (needle[i] == needle[border[i]]) border[i]++;
  }
  
  int n = t.size();
  int seen = 0;
  for (ini; ini < n; ini++) {
    while (seen > 0 and t[ini] != needle[seen])
      seen = border[seen - 1];
    if (t[ini] == needle[seen]) seen++; 
    if (seen == m) {
      ini++; //Next time start in next letter after this occur
      return true;
    }
  }
  return false;
}

int
main() {
  while (cin >> cas) {
    cin >> t;
    for (int i = 0; i < cas; i++) {
      cin >> p;
      istringstream ss(p);
      string subp;
      ini = 0;
      bool can = true;
      while (can && getline(ss, subp, '*')) {
        if (subp != "") {
          can &= kmp(subp);
        } 
      }
      if (can) cout << "yes" << endl;
      else cout << "no" << endl;
    }
     
  }
  return 0;
}
