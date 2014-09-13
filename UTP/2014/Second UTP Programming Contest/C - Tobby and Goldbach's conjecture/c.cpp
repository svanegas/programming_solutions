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

const int MAXN = 400;
bool sieve[MAXN + 5];
vector <int> primes;
int a, n;

void
build_sieve() {
  memset(sieve, false, sizeof sieve);
  sieve[0] = sieve[1] = true;
  
  for (int i = 2; i * i <= MAXN; i++) {
    if (!sieve[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        sieve[j] = true; 
      } 
    } 
  }
  for (int i = 2; i <= MAXN; i++) {
    if (!sieve[i]) primes.push_back(i); 
  }  
}

int
main() {
  build_sieve();
  cin >> a;
  while (a--) {
    int xi; cin >> xi;
    int ans = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] > xi) break;
      for (int j = i; j < primes.size(); j++) {
        if (primes[i] + primes[j] == xi) ans++;
      }
    } 
    cout << ans << endl;
  }
  return 0;
}
