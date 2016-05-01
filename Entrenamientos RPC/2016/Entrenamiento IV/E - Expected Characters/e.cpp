#include <bits/stdc++.h>

using namespace std;

int
main() {
  char s[1000001]; int q, i, j, k, ind, len;
  while (scanf("%s %d", s, &q) == 2) {
    len = strlen(s);
    while (q--) {
      scanf("%d %d", &i, &j);
      printf("%c\n", s[(i + j - 2) % len]);
    }
  }
  return 0;
}
