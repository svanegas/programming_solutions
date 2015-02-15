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

int n, p, inf = 0, inb = 0, mine = -1;
deque <int> pizzas;

/* Turn: 1 - back
         2 - front
         3 - me */
bool play(deque <int> items, int turn) {
  if (items.size() == 1) return (items[0] == mine);
  if (turn == 1) {
    if (items.back() == mine) return false;
    items.pop_back();
    return play(items, 2);
  }
  else if (turn == 2) {
    if (items.front() == mine) return false;
    items.pop_front();
    return play(items, 3);
  }
  else {
    bool can = false;
    for (int i = 0; i < items.size(); ++i) {
      deque <int> poss;
      if (items[i] == mine) continue;
      for (int j = 0; j < i; ++j) poss.push_back(items[j]);
      for (int j = i + 1; j < items.size(); ++j) poss.push_back(items[j]);
      can |= play(poss, 1);
      if (can) break;
    }
    return can;
  }
}

int
main() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    int xi; cin >> xi;
    string name; cin >> name;
    pizzas.push_back(xi);
    if (i == p) mine = xi;
    else if (mine == -1) inf++;
    else inb++;
  }
  bool can = true;
  //Jugar manteniendo la pizza preferida en la mitad, hasta que hayan 13
  //pizzas para aplicar algoritmo recursivo de orden 2^n
  while (pizzas.size() > 13) {
     if (pizzas.back() == mine) {
      can = false;
      break;
    }
    else pizzas.pop_back();
    inb--;
    if (pizzas.front() == mine) {
      can = false;
      break; 
    }
    else pizzas.pop_front();
    inf--;
    
    if (inf == 0 || inb == 0) {
      can = false;
      break; 
    }
    else if (inf > inb) pizzas.pop_front();
    else pizzas.pop_back();
  }
  if (can) {
    if (play(pizzas, 1)) puts("YES");
    else puts("NO");
  }
  else puts("NO");
  return 0;
}

