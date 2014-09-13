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

int
main() {
  while (cin >> n && n) {
    priority_queue <ll, vector <ll>, greater <ll> > q;
    for (int i = 0; i < n; i++) {
      ll xi; cin >> xi;
      q.push(xi);
    }
    ll ans = 0;
    while (q.size() >= 2) {
      ll sum = 0;
      sum += q.top(); q.pop();
      sum += q.top(); q.pop();
      ans += sum;
      q.push(sum);
    }
    cout << ans << endl;
  } 
  return 0;
}
