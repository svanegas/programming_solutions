// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXF = 12;
int n;
int fact[MAXF];

void
build() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 10; ++i) fact[i] = fact[i - 1] * i;
}

int
main() {
  build();
  while (scanf("%d", &n) != EOF) {
    int ans = 0;
    for (int i = 8; i >= 1; --i) {
      while (n >= fact[i]) {
        ans++;
        n -= fact[i];
      }
    }
    printf("%d\n", ans);
  }
}
