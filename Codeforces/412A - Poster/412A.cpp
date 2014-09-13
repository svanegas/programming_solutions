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
string slogan;

int
main() {
  cin >> n >> k;
  cin >> slogan;
  double mid = (double) (slogan.size() + 1) / 2.0;
  if (k > mid) {
    k--;
    while (k + 1 < n) {
      puts("RIGHT");
      k++;
    }
    while (k >= 0) {
      printf("PRINT %c\n", slogan[k--]); 
      if (k >= 0) puts("LEFT");
    }
  }
  else {
    k--;
    while (k - 1 >= 0) {
      puts("LEFT");
      k--;
    }
    while (k < n) {
      printf("PRINT %c\n", slogan[k++]); 
      if (k < n) puts("RIGHT");
    }
  }
  return 0;
}
