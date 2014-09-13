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

const int MAXN = 100;
int t, z, ans;
char field[MAXN];

int
main() {
  cin >> t;
  z = 1;
  while (t--) {
    ans = 0;
    scanf("%*d %s", field);
    for (int i = 0; i < strlen(field); i++) {
      if (field[i] == '.') {
        i += 2;
        ans++;
      }
    }
    printf("Case %d: %d\n", z++, ans);
  }  
  return 0;
}
