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

string s;
int a, c, g, t;

int
main() {
  cin >> s;
  a = c = g = t = 0;
  for (int i = 0; i < s.size(); i++) {
    a += (s[i] == 'A');
    c += (s[i] == 'C');
    g += (s[i] == 'G');
    t += (s[i] == 'T');
  }
  printf("%d %d %d %d\n", a, c, g, t);
  return 0;
}
