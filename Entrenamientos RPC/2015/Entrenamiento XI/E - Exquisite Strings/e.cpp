#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAX_N = 100010;
string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int LCP[MAX_N], Phi[MAX_N], PLCP[MAX_N];
ll got[MAX_N];
ll acum[MAX_N];
int c[MAX_N];

void countingSort(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)
  tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() {
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tempRA[SA[i]] =
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
  }
}

void
build_add() {
  got[0] = 0LL;
  got[1] = 1LL;
  for (int i = 2; i < MAX_N; ++i) {
    got[i] = i + got[i - 1];
    got[i] %= MOD;
  }
}

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1];
  for (i = L = 0; i < n; i++) {
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    while (T[i + L] == T[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  build_add();
  int t; cin >> t;
  int z = 1;
  while (t--) {
    int k;
    cin >> T >> k;
    T += "$";
    n = T.size();
    constructSA();
    computeLCP();
    ll ans = 0LL;
    for (int i = 1; i < n; i++) {
      int diff = n - SA[i] - k - 1;
      acum[i] = max(0LL, diff + 1LL);
      if (LCP[i] >= k && acum[i - 1] >= 0LL) {
        acum[i] += acum[i - 1];
        acum[i] %= MOD;
      }
      if (diff > 0) {
        ll adding = (n - SA[i - 1] - k) * 1LL;
        if (LCP[i] >= k && adding > 0LL) ans += ((diff + 1LL) * acum[i - 1]);
        ans += got[diff];
        ans %= MOD;
      }
    }
    cout << "Case #" << z++ << ": " << ans % MOD << endl;
  }
  return 0;
}
