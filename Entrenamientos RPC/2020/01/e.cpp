#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int MAXN = 2000000;
vector <int> primes;
priority_queue <ll> solv;

void solve(int maxPrime, int k) {
  vector<bool> originalSieve(MAXN + 5, false);
  vector<bool> limitedSieve(MAXN + 5, false);

  originalSieve[0] = true; originalSieve[1] = true;
  limitedSieve[0] = true; limitedSieve[1] = true;

  for (int i = 2; i <= maxPrime; ++i) {
    if (!limitedSieve[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        limitedSieve[j] = true;
      }
    }
  }

  for (int i = 2; i * i <= MAXN; ++i) {
    if (!originalSieve[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        originalSieve[j] = true;
      }
    }
  }

  int ans = -1, compositeNumbers = 0;
  for(int i = 0; i <= MAXN && ans == -1; ++i) {
    if(!limitedSieve[i] && originalSieve[i]) compositeNumbers++;
    if(compositeNumbers == k) ans = i;
  }

  cout << ans << endl;
}


int main() {
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}
