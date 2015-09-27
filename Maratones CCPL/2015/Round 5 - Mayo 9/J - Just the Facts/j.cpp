#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int last[MAXN], dp[MAXN];
int n;

void
build() {
  dp[0] = 1;
  last[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    dp[i] = dp[i - 1] * i;
    while (dp[i] % 10 == 0) dp[i] /= 10;
    last[i] = dp[i] % 10;
    dp[i] %= 100000;
  }
}

int
main() {
  build();
  while (scanf("%d", &n) != EOF) {
    printf("%5d -> %d\n", n, last[n]);
  }
  return 0;
}
