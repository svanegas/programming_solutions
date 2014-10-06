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

int t, n;
vector <char> game;

void
play(bool turn) {
  bool played = false;
  for (int i = 1; i < game.size(); ++i) {
    if ((turn && game[i - 1] != game[i]) || (!turn && game[i - 1] == game[i])) {
      game.erase(game.begin() + (i - 1));
      game.erase(game.begin() + (i - 1));
      game.insert(game.begin() + (i - 1), turn ? 'l' : 'h');
      played = true;
      break;
    }
  }
  if (!played) {
    game.pop_back();
    game.pop_back();
    game.push_back(turn ? 'h' : 'l');
  }
}

int
main() {
  cin >> t;
  while (t--) {
    game.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string s; cin >> s;
      game.push_back(s[0]);
    }
    bool turn = true; //True = l, false = h
    while (game.size() > 1) {
      play(turn);
      turn = !turn;
    }
    cout << (game[0] == 'l' ? "lxh" : "hhb") << endl;
  }
  return 0;
}
