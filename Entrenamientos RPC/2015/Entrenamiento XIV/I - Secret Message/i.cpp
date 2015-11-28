#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
char arr[MAXN][MAXN];

int
next(int num) {
  return (int) ceil(sqrt(num * 1.0));
}

int
main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string msg; cin >> msg;
    int sz = msg.size();
    int caca = next(sz);
    int ind = 0;
    for (int i = 0; i < caca; ++i) {
      for (int j = 0; j < caca; ++j) {
        if (ind < sz) arr[i][j] = msg[ind++];
        else arr[i][j] = '*';
      }
    }
    for (int j = 0; j < caca; ++j) {
      for (int i = caca - 1; i >= 0; --i) {
        if (arr[i][j] != '*') cout << arr[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
