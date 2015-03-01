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

//157.253.238.31
//team608
//539207a2

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 105;
bool sieve[MAXN + 5];
vector <int> primes;
long long n;
vector <long long> arr[MAXN];

void
build_sieve() {
  memset(sieve, false, sizeof(sieve));
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

vector <long long>
factorization(long long a) {
  vector <long long> ans;
  long long b = a;
  for (int i = 0; 1LL * primes[i] * primes[i] <= a; i++) {
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
  for (int i = 2; i <= 101; i++) arr[i] = factorization(i); 
  while (cin >> n && n) {
    map <int, int> m;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < arr[i].size(); j++) {
        m[arr[i][j]]++;
      } 
    }
    vector <int> ans;
    map <int, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
      ans.push_back(it->second);
    }
    if (toStr(n).size() == 2) {
      printf(" %d! =", n); 
    }
    else if (toStr(n).size() == 1) {
      printf("  %d! =", n); 
    }
    else {
      printf("%d! =", n);
    }
    if (ans.size() > 15) {
      for (int i = 0; i < 15; i++) {
        if (toStr(ans[i]).size() == 2) {
          printf(" %d", ans[i]); 
        }
        else {
          printf("  %d", ans[i]);
        }
      } 
      printf("\n      ");
      for (int i = 15; i < ans.size(); i++) {
        if (toStr(ans[i]).size() == 2) {
          printf(" %d", ans[i]); 
        }
        else {
          printf("  %d", ans[i]);
        }
      }
    }
    else {
     for (int i = 0; i < ans.size(); i++) {
        if (toStr(ans[i]).size() == 2) {
          printf(" %d", ans[i]); 
        }
        else {
          printf("  %d", ans[i]);
        }
      }  
    }
    puts("");
  }
  return 0;
}
