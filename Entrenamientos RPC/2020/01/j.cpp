#include <bits/stdc++.h>

using namespace std;

int n, c, total;

int main() {
  scanf("%d %d", &n, &c);
  if (n >= 2) {
    total = -((n - 1) * c);
  } else {
    total = 0;
  }
  while (n--) {
    int mins, secs;
    scanf("%d:%d", &mins, &secs);
    total += secs;
    total += mins * 60;
  }
  printf("%02d:%02d:%02d\n", total / 60 / 60, (total / 60) % 60, total % 60);
  return 0;
}
