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

map <string, map <string, int> > m;

void
build() {
  map <string, int> v;
  v["Kamen"] = 1; v["Nuzky"] = 2; v["Papir"] = 3;
  m["cs"] = v;
  v["Rock"] = 1; v["Scissors"] = 2; v["Paper"] = 3;
  m["en"] = v;
  v["Pierre"] = 1; v["Ciseaux"] = 2; v["Feuille"] = 3;
  m["fr"] = v;
  v["Stein"] = 1; v["Schere"] = 2; v["Papier"] = 3;
  m["de"] = v;
  v["Ko"] = 1; v["Koe"] = 1; v["Ollo"] = 2; v["Olloo"] = 2; v["Papir"] = 3;
  m["hu"] = v;
  v["Sasso"] = 1; v["Roccia"] = 1; v["Forbice"] = 2; v["Carta"] = 3; v["Rete"] = 3;
  m["it"] = v;
  v["Guu"] = 1; v["Choki"] = 2; v["Paa"] = 3;
  m["jp"] = v;
  v["Kamien"] = 1; v["Nozyce"] = 2; v["Papier"] = 3;
  m["pl"] = v;
  v["Piedra"] = 1; v["Tijera"] = 2; v["Papel"] = 3;
  m["es"] = v;
}

string p1, p2;
string n1, n2;

int
main() {
  build();
  int z = 1;
  while (cin >> p1 && p1 != ".") {
    cin >> n1 >> p2 >> n2;
    string juga1, juga2;
    int punt1 = 0, punt2 = 0;
    while (cin >> juga1 && juga1 != "-") {
      cin >> juga2;
      int que1 = m[p1][juga1];
      int que2 = m[p2][juga2];
      if (que1 == 1 && que2 == 2) punt1++;
      if (que1 == 2 && que2 == 3) punt1++;
      if (que1 == 3 && que2 == 1) punt1++;
      if (que2 == 1 && que1 == 2) punt2++;
      if (que2 == 2 && que1 == 3) punt2++;
      if (que2 == 3 && que1 == 1) punt2++;
    }
    printf("Game #%d:\n", z++);
    printf("%s: %d point%s\n", n1.c_str(), punt1, punt1 == 1 ? "" : "s");
    printf("%s: %d point%s\n", n2.c_str(), punt2, punt2 == 1 ? "" : "s");
    if (punt1 == punt2) puts("TIED GAME");
    else if (punt1 > punt2) printf("WINNER: %s\n", n1.c_str());
    else printf("WINNER: %s\n", n2.c_str());
    puts("");
  }
  return 0;
}
