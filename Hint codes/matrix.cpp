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

void
printMatrix(int **mat, int n, int m) {
  int dir = 1;
  bool byColumns = true;
  int i = 0, j = 0;
  int elements = m * n;
  int printed = 0;
  while (printed < elements) {
    if (byColumns) { //Left or right
      int times = m--;
      for (int count = 0; count < times; ++count) {
        cout << mat[i][j]  << " ";
        j += dir;
        printed++;
      }
      j -= dir;
      i += dir;
    }
    else { //Up or down
      int times = (n--) - 1;
      for (int count = 0; count < times; ++count) {
        cout << mat[i][j] << " ";
        i += dir;
        printed++;
      }
      i -= dir;
      dir = dir == -1 ? 1 : -1;
      j += dir;
    }
    byColumns = !byColumns;
  }
  puts("");
}

int
main() {
  int n, m;
  while (cin >> n >> m && n && m) {
    int **pMat;
    pMat = new int*[n];
    for (int i = 0; i < n; ++i) {
      pMat[i] = new int[m];
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        pMat[i][j] = x; 
      } 
    }
    printMatrix(pMat, n, m);
  }
  return 0;
}
