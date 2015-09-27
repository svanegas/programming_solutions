#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 33000;
bool sieve[MAXN + 5];
vector <int> primes;
int t, n, d;

void build_sieve() {
  memset(sieve, false, sizeof(sieve));
  sieve[0] = sieve[1] = true;
  for (int i = 2; i * i <= MAXN; i ++){
    if (!sieve[i]){
      for (int j = i * i; j <= MAXN; j += i){
        sieve[j] = true;
      }
    }
  }
  for (int i = 2; i <= MAXN; ++i){
    if (!sieve[i]) primes.push_back(i);
  }
}

map <int, int> factorization(int a){
  map <int, int> ans;
  int b = a;
  for (int i = 0; primes[i] * primes[i] <= a; ++i){
    int p = primes[i];
    while (b % p == 0){
      ans[p]++;
      b /= p;
    }
  }
  if (b != 1) ans[b]++;
  return ans;
}

int
main() {
  build_sieve();
  //cin >> t;
  scanf("%d", &t);
  while (t--) {
    //cin >> n >> d;
    scanf("%d %d", &n, &d);
    map <int, int> maxi;
    for (int i = 0; i < n; ++i) {
      int xi;
      //cin >> xi;
      scanf("%d", &xi);
      map <int, int> facts = factorization(xi - d);
      map <int, int> :: iterator it;
      for (it = facts.begin(); it != facts.end(); ++it) {
        maxi[it->first] = max(maxi[it->first], it->second);
      }
    }
    ll ans = 1LL;
    map <int, int> :: iterator it;
    for (it = maxi.begin(); it != maxi.end(); ++it) {
      ll base = 1LL * (it->first);
      int times = it->second;
      double add = pow((double) base, (double) times);
      ans *= ((ll) add);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
