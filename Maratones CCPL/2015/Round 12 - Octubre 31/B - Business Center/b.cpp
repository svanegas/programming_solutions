#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 1000000005LL;

int main() {
  int n, m;
  while (cin >> n >> m) {
    ll ans = MAXN;
    ll maxi, aux;
    for (int i = 0; i < m; ++i) {
      int u, d, b = 0;
      cin >> u >> d;
      ll curr = 0;
      maxi = (u * n) / (u + d);
      aux = u * (n - maxi) - d * maxi;
      if (aux == 0LL) {
        maxi = max(0LL, maxi - 1);
        aux = u * (n - maxi) - d * maxi;
      }
      ans = min(ans, aux);
    }
    cout << ans << endl;
  }
  return 0;
}

/*
10 3
15 12
15 4
7 12
*/
