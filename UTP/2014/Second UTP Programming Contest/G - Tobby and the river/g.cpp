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

int a;

int
sumar(vector <int> dogs) {
  int tot = 0;
  for (int i = 0; i < dogs.size(); i++) tot += dogs[i];
  return tot; 
}

bool
solve(int sum, vector<int> dogs) {
  if (sumar(dogs) == sum) return true;
  for (int i = 0; i < dogs.size(); i++) {
    vector <int> nextDogs = dogs;
    nextDogs.erase(nextDogs.begin() + i);
    if (solve(sum + dogs[i], nextDogs))
      return true;    
  }
  return false;
}

int
main() {
  cin >> a;
  while (a--) {
    vector <int> dogs;
    for (int i = 0; i < 6; i++) {
       int xi; cin >> xi;
       dogs.push_back(xi);
    } 
    if (solve(0, dogs)) puts("Tobby puede cruzar");
    else puts("Tobby no puede cruzar");
  }
  return 0;
}
