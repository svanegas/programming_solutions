#include <bits/stdc++.h>

using namespace std;

int
main() {
  int n, z = 1;
  scanf("%d", &n);
  while (n--) {
    int g, p;
    scanf("%d %d", &g, &p);
    printf("Team #%d\n", z++);
    printf("Games: %d\n", g);
    printf("Points: %d\n", p);
    puts("Possible records:");
    for (int w = p / 3; w >= 0; --w) {
      int t = p - w * 3;
      int l = g - w - t;
      if (l >= 0) printf("%d-%d-%d\n", w, t, l);
    }
    puts("");
  }
  return 0;
}
