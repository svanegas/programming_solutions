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
const ll MAXN = 23;
bool sieve[MAXN + 5];
vector<ll> primes;

void
build_sieve() {
  memset(sieve, false, sizeof sieve);
  sieve[0] = sieve[1] = true;
  
  for (ll i = 2LL; i * i <= MAXN; ++i) {
    if (!sieve[i]) {
      for (ll j = i * i; j <= MAXN; j += i) {
        sieve[j] = true; 
      } 
    }
  }
  for (ll i = 2LL; i <= MAXN; ++i) {
    if (!sieve[i]) primes.push_back(i); 
  }
}

ll
minNumber(const string &s) {
  vector <ll> divisible;
  ll ans = 0LL;
  for (ll i = 0LL; i < s.size(); ++i) {
    if (s[i] == 'Y') {
      divisible.push_back(i + 1LL);
      ans = i + 1LL;
    }
    else if (ans == 0LL) ans = i + 2LL;
  }
  vector <ll> factors;
  int index = 0; //prime index
  int oneCount = 0; //counting if we’re done
  bool increment; //Increment prime index
  bool used; //If i used a prime factor to add it to list
  while (oneCount != divisible.size()) {
    increment = false;
    used = false;
    oneCount = 0;
    for (ll i = 0LL; i < divisible.size() * 1LL; ++i) {
      if (divisible[i] == 1LL) oneCount++;
      else if (divisible[i] % primes[index] == 0LL) {
        divisible[i] /= primes[index];
        used = true;
        if (divisible[i] == 1LL) oneCount++;
      }
    }
    if (used) factors.push_back(primes[index]);
    if (!used) index++;
  }
  if (!factors.empty()) {
    ans = 1LL;
    for (ll i = 0LL; i < factors.size(); ++i) {
      ans *= (factors[i] * 1LL);
    }
  }
  for (ll i = 0LL; i < s.size(); ++i) {
    if (s[i] == 'N') {
      if (ans % (i + 1LL) == 0LL) {
        ans = -1LL;
        break;
      }
    }
  }
  return ans;
}

int
main() {
  build_sieve();
  string s;
  while (cin >> s && s != "*") {
    cout << minNumber(s) << endl;
  }
  return 0;
}
