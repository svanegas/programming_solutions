#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXE 23
#define MAXN 10005
#define D(x) cout << #x << " " << x << endl;

ll pot[MAXE];
ll dp[MAXN];

ll opow(ll base, int expo) {
 ll ans = base;
 for(int i = 1; i < expo; ++i) ans *= base;
 return ans;
}

void buildPot() {
  pot[0] = 1;
  for(int i = 1; i < MAXE; ++i) pot[i] = opow(i, 3);
  for(int i = 0; i < MAXN; ++i) dp[i] = 1LL;
  for(int i = 2; i < MAXE; ++i) {
    for(int j = pot[i]; j < MAXN; ++j) dp[j] += dp[j - pot[i]];
  }
}

int main() {
  buildPot();
  int n;
  while (cin >> n) cout << dp[n] << endl;
  return 0;
}
