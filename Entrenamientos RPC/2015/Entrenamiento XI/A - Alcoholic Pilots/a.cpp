#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int
main() {
  ll v1, d1, v2, d2;
  int z = 1;
  while (scanf("%lld %lld %lld %lld", &v1, &d1, &v2, &d2) != EOF && v1) {
    ll num = d1 * v2 + v1 * d2;
    ll den = v1 * v2 * 2LL;
    ll by = __gcd(num, den);
    num /= by;
    den /= by;
    printf("Case: #%d: ", z++);
    ll mcm = ((v1 * v2) / __gcd(v1, v2));
    ll one = d1 * (mcm / v1);
    ll two = d2 * (mcm / v2);
    if (one < two) puts("You owe me a beer!");
    else puts("No beer for the captain.");
    printf("Avg. arrival time: %lld", num);
    if (den > 1LL) printf("/%lld", den);
    puts("");
  }
  return 0;
}
