#include <bits/stdc++.h>

using namespace std;

int
main() {
  for (int k = 0; k < 100; ++k) {
    cout << 1000 << endl;
    for (int i = 0; i < 1000; ++i) {
      cout << (rand() % 1000);
      for (int j = 1; j < 1000; ++j) {
        cout << " " << (rand() % 1000);
      }
      cout << endl;
    }
  }
  cout << 0 << endl;
  return 0;
}
