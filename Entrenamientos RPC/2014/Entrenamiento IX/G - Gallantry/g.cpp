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

typedef long long ll;
int n, turnsYield;
vector <ll> players, diff;

int
main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll xi; cin >> xi;
    players.push_back(xi);
  }
  sort(players.begin(), players.end());
  vector <ll> diff;
  bool victory = false;
  for (int i = 1; i < n; i += 2) {
    diff.push_back(players[i] - players[i-1]);
    if (players[i] - players[i-1] != 0) victory = true;
  }
  if (victory) {
    sort(diff.rbegin(), diff.rend());
    ll german = 0LL;
    int i;
    bool won = false;
    for (i = 0; i < diff.size() && !won; ++i) {
      german += diff[i];
      ll gianina = 0LL;
      for (int j = i + 1; j < diff.size(); ++j) {
        gianina += diff[j]; 
      }
      if (german > gianina) won = true;
    }
    turnsYield = diff.size() - i;
  }
  else turnsYield = -1;
  cout << turnsYield << endl;
  return 0;
}
