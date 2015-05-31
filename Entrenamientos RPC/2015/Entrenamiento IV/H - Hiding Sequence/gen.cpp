#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;

int
main() {
  cout << MAXN << endl;
  cout << "1";
  for (int i = 1; i < MAXN; ++i) {
    cout << " " << (i % 2 == 0 ? 1 : -1);
  }
  cout << endl;
  return 0;
}
