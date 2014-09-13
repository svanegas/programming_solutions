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

int t, os, xs;
char table[3][3];

bool
wins(char p) {
  for (int i = 0; i < 3; i++) {
    int contHor, contVer, contDiag1, contDiag2;
    contHor = contVer = contDiag1 = contDiag2 = 0;
    for (int j = 0; j < 3; j++) {
      contHor += (table[i][j] == p);
      contVer += (table[j][i] == p);
      contDiag1 += (table[j][j] == p);
      contDiag2 += (table[2-j][j] == p);
    }
    if (contHor == 3 || contVer == 3 ||
        contDiag1 == 3 || contDiag2 == 3) return true;
  }
  return false;
}

bool
solve() {
  if (os > xs) return false;
  if (xs - os >= 2) return false;
  if (wins('X') && wins('O')) return false;
  if (wins('O') && xs != os) return false;
  if (wins('X') && xs != os + 1) return false;
  return true;
}

int
main() {
  cin >> t;
  while (t--) {
    os = xs = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> table[i][j];
        os += (table[i][j] == 'O');
        xs += (table[i][j] == 'X');
      }
    }
    
    if (solve()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
