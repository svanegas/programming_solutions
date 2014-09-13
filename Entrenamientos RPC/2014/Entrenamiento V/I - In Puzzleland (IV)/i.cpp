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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int c, h1, s, h2, num, den;

int
main() {
  cin >> c;
  for (int i = 1; i <= c; i++) {
    printf("Case %d: ", i);
    cin >> h1 >> s >> h2;
    h1--; h2--;
    num = s * h2;
    den = h1;
    int gcd = __gcd(num, den);
    num /= gcd;
    den /= gcd;
    if (den == 1) printf("%d\n", num);
    else if (num > den) printf("%d %d/%d\n", num/den, num%den, den);
    else printf("%d/%d\n", num, den);
  }
  return 0;
}
