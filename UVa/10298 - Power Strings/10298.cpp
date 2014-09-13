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

const int MAXN = 1000002;
char s[MAXN];

int
main() {
  while (scanf("%s", s)) {
    int m = strlen(s);
    if (m == 1 && s[0] == '.') break;
    
    int maxi = 0;
    vector <int> border(m);
    border[0] = 0;
    
    for (int i = 1; i < m; i++) {
      border[i] = border[i - 1];
      while (border[i] > 0 && s[i] != s[border[i]]) {
        border[i] = border[border[i] - 1];
      }
      if (s[i] == s[border[i]]) border[i]++; 
    }
    int base = m - border[m - 1];
    if (m % base == 0) printf("%d\n", m / base);
    else printf("%d\n", 1);
  }
  return 0;
}

