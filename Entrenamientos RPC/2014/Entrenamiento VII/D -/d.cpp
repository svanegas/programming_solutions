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
const ll MOD = 1000003;
int n;
ll totLeft, totRight, totForward;

void
computeExpressionList(ll factor) {
  string expr;
  while (cin >> expr && expr != "end" && expr != "]") {
    ll value;
    cin >> value;
    if (expr == "left") {
      totLeft += (((value % MOD) * (factor % MOD)) % MOD);
      totLeft %= MOD;
    }
    else if (expr == "right") {
      totRight += (((value % MOD) * (factor % MOD)) % MOD);
      totRight %= MOD;
    }
    else if (expr == "forward") {
      totForward += (((value % MOD) * (factor % MOD)) % MOD);
      totForward %= MOD;
    }
    else if (expr == "repeat") {
      cin >> expr; //Read the "["
      computeExpressionList(((factor % MOD) * (value % MOD)) % MOD);
    }
  }
}

int
main() {
  cin >> n;
  string expr;
  while (n--) {
    totLeft = totRight = totForward = 0LL;
    cin >> expr; //Read begin
    computeExpressionList(1LL);
    cout << totLeft << " " << totRight << " " << totForward << endl;
  }
  return 0;
}
