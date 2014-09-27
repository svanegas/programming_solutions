using namespace std;
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define D(x) cout << #x " = " << (x) << endl;

const double EPS = 1e-9;

int n, k, x;
map <vector <int>, int> m;
vector <int> group;

int
balls(vector <int> game) {
  if (game.size() < 3) return 0;
  int maxi = 0;
  if (m[game] > 0) return m[game];
  int cont = 0, ini = 0, col = game[0];
  for (int i = 0; i < game.size(); i++) {
    if (game[i] == col) cont++;
    else {
      if (cont >= 3) {
        vector <int> next = game;
        next.erase(next.begin() + ini, next.begin() + ini + cont);
        maxi = max(cont + balls(next), maxi);
      }
      ini = i;
      cont = 0;
      col = game[i];
      i--;
    } 
  }
  if (cont >= 3) {
    vector <int> next = game;
    next.erase(next.begin() + ini, next.begin() + ini + cont);
    maxi = max(cont + balls(next), maxi);
  }
  return m[game] = maxi;
}

int
solve(vector <int> s) {
  int maxi = 0;
  for (int i = 0; i < group.size(); i++) {
    int ind = group[i];
    if (s[ind] == x) {
      vector <int> next = s;
      next.insert(next.begin() + ind, x);
      maxi = max(maxi, balls(next)); 
    }
  }
  return maxi - 1;
}

int
main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> k >> x && n) {
    m.clear();
    group.clear();
    vector <int> game;
    int actual;
    for (int i = 0; i < n; i++) {
      int col;
      cin >> col;
      game.push_back(col);
      if (i == 0) {
        actual = game[i];
        group.push_back(i);
      }
      else {
        if (game[i] != actual) {
          group.push_back(i);
          actual = game[i]; 
        }
      }
    }
    cout << max(0, solve(game)) << endl;
  }
  return 0;
}
