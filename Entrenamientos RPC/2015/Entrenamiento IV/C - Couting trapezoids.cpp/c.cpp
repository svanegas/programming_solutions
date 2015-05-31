#include <bits/stdc++.h>

using namespace std;

const int MAXSQ = 31625;
bool sieve[MAXSQ + 15];
vector <int> primes;
int n;

void
build_sieve() {
  memset(sieve, false, sizeof(sieve));
  sieve[0] = sieve[1] = true;

  for (int i = 2; i * i <= MAXSQ + 10; ++i) {
    if (!sieve[i]) {
      for (int j = i * i; j <= MAXSQ + 10; j += i) {
        sieve[j] = true;
      }
    }
  }
  for (int i = 2; i <= MAXSQ + 10; ++i) {
    if (!sieve[i]) primes.push_back(i);
  }
}

vector <int> factorization(int a) {
  vector <int> ans;
  int b = a;
  for (int i = 0; primes[i] * primes[i] <= a; ++i) {
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
  while (cin >> n) {
    vector <int> fact = factorization(n);
    map <int, int> m;
    for (int i = 0; i < fact.size(); ++i) if (fact[i] > 2) m[fact[i]]++;

    int ans = 1;
    map <int, int> :: iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
      ans *= (it->second + 1);
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
