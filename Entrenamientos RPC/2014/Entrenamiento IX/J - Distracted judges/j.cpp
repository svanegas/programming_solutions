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

const int MAXN = 100005;
int n;
int arr[MAXN];

bool
prod(int i) {
  if (i > n) return false;
  if (i == n) return true;
  return prod(i + arr[i] + 1);
}

int
main() {
  n = 0;
  while (cin >> arr[n++]);
  n--;
  for (int i = 1; i < n; ++i) {
    arr[0] = i;
    if (prod(0)) cout << i << endl;
  }
  return 0;
}
