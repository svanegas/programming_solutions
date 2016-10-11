#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int len[MAXN];
int starts[MAXN];
int a, b, n;
string text;

int
main() {
  while (getline(cin, text) && scanf("%d %d", &a, &b) != EOF) {
    getchar();
    text += " ";
    n = text.size();
    starts[0] = 0;
    for (int i = 1; i < n; ++i) {
      if (text[i] == ' ') {
        starts[i] = i + 1;
        len[starts[i - 1]] = starts[i] - starts[i - 1] - 1;
      }
      else starts[i] = starts[i - 1];
    }
    text[text.size() - 1] = '\0';
    n--;
    for (int k = a; k <= b; ++k) {
      int ind = 0, ans = 0;
      while (ind < n) {
        ind = starts[ind];
        ans += len[ind] + 1;
        ind += k;
      }
      printf("%d\n", ans - 1);
    }
  }
  return 0;
}
