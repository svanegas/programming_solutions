// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, b;

ll
binary() {
  ll lo = 1LL, hi = n / 2LL;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2LL;
    if (4 * mid * (n - mid) >= b) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}

ll
prev_beans(ll pos) {
  ll ans = 4LL * pos * (n - pos);
  if (b == ans) return ans;
  else if (pos - 1 >= 1) return 4LL * (pos - 1) * (n - (pos - 1));
  else return 0LL;
}

int
main() {
  while (scanf("%lld %lld", &n, &b) != EOF) {
    ll it, beans, rem, comp, len, i, j;
    it = binary();
    rem = b - prev_beans(it);
    comp = it - 1LL; len = n - 2LL * comp;
    if (rem == 0LL) comp++;
    i = 1LL + comp, j = comp;
    // Right
    j += min(len, rem);
    rem -= min(len, rem);
    len = max(0LL, len - 1LL);
    // Down
    i += min(len, rem);
    rem -= min(len, rem);
    // Left
    j -= min(len, rem);
    rem -= min(len, rem);
    len = max(0LL, len - 1LL);
    // Up
    i -= min(len, rem);
    printf("%lld %lld\n", i, j);
  }
  return 0;
}
