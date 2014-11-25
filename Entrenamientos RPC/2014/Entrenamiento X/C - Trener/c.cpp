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

int team[30];
int n;

int
main() {
  for (int i = 0; i <= 26; ++i) team[i] = 0; 
  cin >> n;
  bool some = false;
  for (int i = 0; i < n; ++i) {
    string name; cin >> name;
    team[name[0] - 'a']++; 
    some |= team[name[0] - 'a'] >= 5;
  }
  if (!some) puts("PREDAJA");
  else {
    for (int i = 0; i < 26; ++i)
      if (team[i] >= 5) cout << (char) (i + 'a'); 
    puts("");
  }
  return 0;
}
