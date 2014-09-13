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

const int MAXN = 105;
bool sieve[MAXN];
vector <int> primes;
int n;

void
build_sieve() {
  memset(sieve, false, sizeof(sieve));
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

vector <int>
factorization(int a) {
  vector <int> ans;
  int b = a;
  for (int i = 0; primes[i] * primes[i] <= a; i++) {
    int p = primes[i];
    while (b % p == 0) {
      ans.push_back(p);
      b /= p; 
    } 
  }  
  if (b != 1) ans.push_back(b);
  return ans;
}

int
main() {
  build_sieve();
  while (cin >> n && n) {
    map <int, int> m;
    for (int i = 2; i <= n; i++) {
      vector <int> a = factorization(i);
      for (int k = 0; k < a.size(); k++) {
        m[a[k]]++;
      }
    }
    printf("%3d! =", n);
    map <int, int> :: iterator it;
    int times = 0;
    for (it = m.begin(); times < 15 && it != m.end(); it++) {
      times++;
      printf("%3d", it->second);
    }
    if (times >= 15 && it != m.end()) {
      printf("\n      ");
      for (it; it != m.end(); it++) {
        printf("%3d", it->second);
      }
    }
    puts("");
  }
  return 0;
}
