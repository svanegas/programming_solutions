#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 12000005;
bool sieve[MAXN + 5];
vector <int> primes;

void build_sieve() {
  memset(sieve, false, sizeof(sieve));
  sieve[0] = sieve[1] = true;

  for (int i = 2; i * i <= MAXN; ++i) {
    if (!sieve[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        sieve[j] = true;
      }
    }
  }
  for (int i = 2; i <= MAXN; ++i) {
    if (!sieve[i]) primes.push_back(i);
  }
}

ll fact(ll a) {
  ll ans = 0LL;
  ll b = a;
  for (int i = 0; 1LL * primes[i] * primes[i] <= a; ++i) {
    int p = primes[i];
    while (b % p == 0LL) {
      ans++;
      b /= p;
    }
  }
  if (b != 1LL) ans++;
  return ans;
}

int
main() {
  build_sieve();
  ll n;
  while (cin >> n && n != 1LL) cout << fact(n) << endl;
  return 0;
}
