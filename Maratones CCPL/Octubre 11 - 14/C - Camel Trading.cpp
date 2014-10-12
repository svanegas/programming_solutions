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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

//team896
//54381374

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

template <class T> long long toLL(const T &x)
{ stringstream s; s << x; long long r; s >> r; return r; }

typedef long long ll;
typedef pair <ll, char> fact;
int n;
string expr;
vector <fact> factors;

void
processExpr() {
  string numStr = "";
  int i = 0;
  while (i < expr.size()) {
    if (isdigit(expr[i])) numStr += expr[i];
    else {
      ll num = toLL(numStr);
      numStr = "";
      factors.push_back(fact(num, expr[i]));
    }
    ++i;
  }
  ll num = toLL(numStr);
  numStr = "";
  factors.push_back(fact(num, '*'));
}

ll
computeMaxi() {
  vector <ll> maxi;
  ll acum = 0LL;
  for (int i = 0; i < factors.size(); ++i) {
    acum += factors[i].first;
    if (factors[i].second == '*') {
      maxi.push_back(acum);
      acum = 0LL; 
    }
  }
  ll ans = 1LL;
  for (int i = 0; i < maxi.size(); ++i) ans *= maxi[i];
  return ans;
}

ll
computeMini() {
  vector <ll> mini;
  ll acum = 1LL;
  for (int i = 0; i < factors.size(); ++i) {
    acum *= factors[i].first;
    if (factors[i].second == '+') {
      mini.push_back(acum);
      acum = 1LL; 
    }
  }
  mini.push_back(acum);
  ll ans = 0LL;
  for (int i = 0; i < mini.size(); ++i) ans += mini[i];
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    factors.clear();
    cin >> expr;
    processExpr();
    printf("The maximum and minimum are %lld and %lld.\n", computeMaxi(), computeMini());
  }
  return 0;
}

