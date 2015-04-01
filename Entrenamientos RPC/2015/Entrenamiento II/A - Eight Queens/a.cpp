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

char board[8][8];

bool
check(int a, int b) {
  for (int i = 1; a - i >= 0; ++i) {
    if (board[a - i][b] == '*') return false;
  }
  for (int i = 1; a + i < 8; ++i) {
    if (board[a + i][b] == '*') return false;
  }
  for (int j = 1; b - j >= 0; ++j) {
    if (board[a][b - j] == '*') return false;
  }
  for (int j = 1; b + j < 8; ++j) {
    if (board[a][b + j] == '*') return false;
  }
  
  for (int i = 1; a - i >= 0 && b + i < 8; ++i) {
    if (board[a - i][b + i] == '*') return false;
  }
  for (int i = 1; a + i < 8 && b + i < 8; ++i) {
    if (board[a + i][b + i] == '*') return false;
  }
  for (int i = 1; a + i < 8 && b - i >= 0; ++i) {
    if (board[a + i][b - i] == '*') return false;
  }
  for (int i = 1; a - i >= 0 && b - i >= 0; ++i) {
    if (board[a - i][b - i] == '*') return false;
  }
  return true;
}

bool
solve() {
  int cont = 0;
  for (int i = 0; i < 8; ++i) {
    string row; cin >> row;
    for (int j = 0; j < 8; ++j) {
      board[i][j] = row[j];
      cont += (board[i][j] == '*');
    }
  }
  bool can = (cont == 8);
  for (int i = 0; i < 8 && can; ++i) {
    for (int j = 0; j < 8 && can; ++j) {
      if (board[i][j] == '*') can &= check(i, j);
    }
  }
  return can;
}

int
main() {
  if (solve()) puts("valid");
  else puts("invalid");
  return 0;
}

