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

int c;
map <char, int> m;

int
main() {
  cin >> c;
  string line;
  getline(cin, line);
  while (c--) {
    m.clear();
    getline(cin, line);
    int n = line.size();
    for (int i = 0; i < n; ++i) {
      if (line[i] != ' ') m[line[i]]++;
    }
    int maxi = 0, cant = 0;
    char letE;
    map <char, int> :: iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
      if (maxi == it->second) cant = 1;
      else if (maxi < it->second) {
        maxi = it->second;
        cant = 0;
        letE = it->first;
      }
    }
    if (cant) puts("NOT POSSIBLE");
    else {
      int d = (int) letE - (int) 'E';
      d = (d + 26) % 26;
      cout << d << " ";
      for (int i = 0; i < n; ++i) {
        if (line[i] != ' ') {
          char cur = line[i];
          //printf("cur1 = %c\n", cur);
          cur -= d;
          if (cur < 65) cur += 26;
          //printf("como resultado: %c\n", cur);
          printf("%c", cur);
        }
        else printf(" ");
      }
      puts("");
    }
  }
  return 0;
}

