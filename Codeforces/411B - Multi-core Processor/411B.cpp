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

const int MAXN = 105;
int n, m, k;
vector <int> cell[MAXN];
int inst[MAXN][MAXN];
int died[MAXN];
bool locked[MAXN];

int
main() {
  memset(cell, 0, sizeof cell);
  memset(died, 0, sizeof died);
  memset(locked, false, sizeof locked);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> inst[i][j];     
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (inst[i][j] != 0 && died[i] == 0) {
        if (locked[inst[i][j]]) {
          died[i] = j + 1; 
        }
        else
          cell[inst[i][j]].push_back(i);
      }
    }
    for (int l = 1; l <= k; l++) {
      if (cell[l].size() > 1) {
        locked[l] = true;
        for (int m = 0; m < cell[l].size(); m++) {
           died[cell[l][m]] = j + 1;
        } 
      } 
      cell[l].clear();
    }
  }
  for (int i = 0; i < n; i++) {
    cout << died[i] << endl; 
  }
  return 0;
}
