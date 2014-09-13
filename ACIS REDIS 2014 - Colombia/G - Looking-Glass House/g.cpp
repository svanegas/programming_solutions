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

const int MAXN = 1000005;
int n;
int got[MAXN];

bool
solve(int base) {
  vector <int> num;
  int aux = n;
  while (aux != 0) {
    num.push_back(aux % base);
    aux /= base;
  }
  int l = 0, h = num.size() - 1;
  while (l <= h) {
    if (num[l] != num[h]) return false;
    l++; h--; 
  }
  return true;
}

int
main() {
  ios::sync_with_stdio(false);
  memset(got, -1, sizeof got);
  while (cin >> n) {
    if (got[n] != -1) {
      cout << got[n] << endl;
      continue; 
    }
    bool can = false;
    int b;
    for (b = 2; b <= n; b++) {
      if (n % b != 0 && solve(b)) {
        can = true;
        got[n] = b;
        break;
      }
    }
    if (can) cout << b << endl;
    else cout << "0" << endl;
  }
  return 0;
}
