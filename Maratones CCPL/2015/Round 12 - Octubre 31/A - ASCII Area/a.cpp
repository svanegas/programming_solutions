#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int h, w;
  while (cin >> h >> w) {
    getchar();
    ll ans = 0LL;
    for (int i = 0; i < h; ++i) {
      stack <int> s;
      for (int j = 0; j < w; ++j) {
        char curr;
        curr = getchar();
        if (curr != '.') s.push(j);
      }
      getchar();
      while (!s.empty()) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        ans += (a - b);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

/*
4 4
/\/\
\../
.\.\
..\/
*/
