// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

int
main() {
  int p;
  while (scanf("%d", &p) != EOF) {
    complex <double> comp(-1, 1);
    complex <double> ans(0, 0);
    int i = 0;
    while (p > 0) {
      if (p % 2) ans += (pow(comp, i));
      p /= 2;
      ++i;
    }
    printf("%d %d\n", (int) real(ans), (int) imag(ans));
  }
  return 0;
}

