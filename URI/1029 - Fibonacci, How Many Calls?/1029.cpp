#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40;
int f[MAXN], fib[MAXN];

int
main() {
  f[0] = f[1] = 0;
  fib[0] = 0; fib[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    f[i] = 2 + f[i - 1] + f[i - 2];
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    printf("fib(%d) = %d calls = %d\n", n, f[n], fib[n]);
  }
  return 0;
}
