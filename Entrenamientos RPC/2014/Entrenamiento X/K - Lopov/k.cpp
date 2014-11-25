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

typedef long long ll;

struct jewell {
  ll mass, val;
  jewell (ll _mass, ll _val) : mass(_mass), val(_val) {}
  
  bool operator < (const jewell &than) const {
    if (mass < than.mass) return true;
    else if (mass == than.mass) return val > than.val;
    else return false;
  }
};

int n, k;
vector <jewell> jewells;
priority_queue <ll> ready;

int
main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    ll mass, val;
    scanf("%lld %lld", &mass, &val);
    jewells.push_back(jewell(mass, val));
  }
  for (int i = 0; i < k; ++i) {
    ll size;
    scanf("%lld", &size);
    jewells.push_back(jewell(size, -1LL));
  }
  sort(jewells.begin(), jewells.end());
  ll ans = 0LL;
  for (int i = 0; i < n + k; ++i) {
    jewell next = jewells[i];
    if (next.val == -1) {
      if (!ready.empty()) {
        ans += ready.top();
        ready.pop();
      }
    }
    else ready.push(next.val);
  }
  printf("%lld\n", ans);
  return 0;
}
