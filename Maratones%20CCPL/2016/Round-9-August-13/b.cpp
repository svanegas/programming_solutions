#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

int numbers[MAXN];
bool f[MAXN];

int
main() {
  int n, b;
  while(cin >> n >> b) {
    if(n == 0 && b == 0) break;
    for(int i = 0; i < b; ++i) cin >> numbers[i];
    for(int i = 0; i <= n; ++i) f[i] = false;
    for(int i = 0; i < b; ++i) {
      for(int j = i + 1; j < b; ++j) {
        int diff = abs(numbers[i] - numbers[j]);
        f[diff] = true;
      }
    }
    bool can = true;
    for(int i = 1; i <= n && can; ++i) {
      if(!f[i]) can = false;
    }
    if(can) cout << "Y" << endl;
    else cout << "N" << endl;
  }
  return 0;
}
