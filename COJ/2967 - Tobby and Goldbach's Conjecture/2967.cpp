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

const int MAXN = 405;
bool sieve[MAXN];
vector <int> primes;
int t, n;

void
build() {
  memset(sieve, false, sizeof sieve);
  sieve[0] = sieve[1] = true;
  
  for (int i = 2; i * i < MAXN; i++) {
    if (!sieve[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        sieve[j] = true; 
      } 
    } 
  }  
  
  for (int i = 2; i < MAXN; i++) {
    if (!sieve[i]) primes.push_back(i); 
  }
}

int
main() {
  build();
  cin >> t;
  while (t--) {
    cin >> n;
    int ways = 0;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
      for (int j = i; j < primes.size() && primes[j] <= n; j++) {
        ways += (primes[i] + primes[j] == n);
      }
    }
    cout << ways << endl;
  }
  return 0;
}
