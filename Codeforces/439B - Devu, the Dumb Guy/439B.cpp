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

typedef long long ll;
int n;
ll x;
priority_queue <ll, vector <ll>, greater <ll> > q;

int
main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    ll xi; cin >> xi; 
    q.push(xi);
  }
  ll tot = 0;
  while (!q.empty()) {
    ll next = q.top(); q.pop();
    tot += (next * x);
    x = max(1LL, x - 1);
  }
  cout << tot << endl;
  return 0;
}
