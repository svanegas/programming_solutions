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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 100005;
int n, q;
ll tank[MAXN];

int binary(int l, int r, ll key) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    (tank[m] >= key ? r : l) = m;
  }
  return r;
}

int
main() {
  while (cin >> n >> q) {
    tank[0] = 1;
    ll xi; cin >> xi;
    for (int i = 1; i < n; i++) {
      cin >> xi;
      tank[i] = tank[i-1] + xi; 
    }
    vector <int> ansvec;
    for (int i = 0; i < q; i++) {
      ll qi; cin >> qi;
      int ans = binary(-1, n-1, qi);
      if (ans > 0 && tank[ans] > qi) ans--;
      ansvec.push_back(ans + 1);
    }
    cout << ansvec[0];
    for (int i = 1; i < q; i++) {
       cout << " " << ansvec[i];
    }
    puts("");
  }
  return 0;
}