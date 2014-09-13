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

const int MAXN = 21;
typedef long long ll;
int t;
ll n, fact[MAXN];
string s, ans;

void
build() {
  fact[0] = 1LL;
  for (ll i = 1LL; i < MAXN; i++) fact[i] = i * fact[i-1];  
}

int
main() {
  build();
  cin >> t;
  while (t--) {
    cin >> s >> n;
    sort(s.begin(), s.end());
    int len = s.size() - 1;
    ans = "";
    while (len >= 0) {
      int i = n / fact[len];
      ans += s[i];
      s.erase(i, 1);
      n %= fact[len];
      len--;
    }
    cout << ans << endl;
  }
  return 0;
}
