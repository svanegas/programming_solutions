#include <bits/stdc++.h>

using namespace std;

int
main() {
  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    if (line[0] == '_') continue;
    int ans = 0;
    int pow = 1;
    for (int i = line.size() - 2; i > 0; --i) {
      if (line[i] == '.') continue;
      if (line[i] == 'o') ans += pow;
      pow *= 2;
    }
    printf("%c", ans);
  }
  return 0;
}
