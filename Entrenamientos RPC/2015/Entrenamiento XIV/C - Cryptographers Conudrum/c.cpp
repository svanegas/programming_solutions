#include <bits/stdc++.h>

using namespace std;

int
main() {
  string text; cin >> text;
  int ans = 0;
  for (int i = 0; i < text.size(); ++i) {
    if (i % 3 == 0) ans += text[i] != 'P';
    else if (i % 3 == 1) ans += text[i] != 'E';
    else ans += text[i] != 'R';
  }
  cout << ans << endl;
  return 0;
}
