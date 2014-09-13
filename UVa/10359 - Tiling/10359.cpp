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

const int MAXN = 255;
string fib[MAXN];
int n;

string
sumar(const string &a, const string &b) {
  int ia = a.size() - 1, ib = b.size() - 1;
  int llevo = 0;
  string ans = "";
  while (ia >= 0 || ib >= 0) {
    int sum = (ia >= 0 ? toInt(a[ia--]) : 0) + (ib >= 0 ? toInt(b[ib--]) : 0);
    sum += llevo;
    llevo = sum / 10;
    ans += toStr(sum % 10);
  }
  if (llevo) ans += toStr(llevo);
  reverse(ans.begin(), ans.end());
  return ans;
}

void
build() {
  fib[0] = fib[1] = "1";
  for (int i = 2; i < MAXN; i++) {
    fib[i] = fib[i-2];
    fib[i] = sumar(fib[i], fib[i-2]);
    fib[i] = sumar(fib[i], fib[i-1]); 
  }
}

int
main() {
  build();
  while (cin >> n) {
    cout << fib[n] << endl;
  }
  return 0;
}
