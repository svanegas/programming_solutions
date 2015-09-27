// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1026;
ll nums[MAXN];
int n;

int
main() {
  cin >> n;
  ll cur, prev;
  bool can = true;
  for (int i = 0; i < n; ++i) {
    cin >> cur;
    if (i > 0) can &= (prev <= cur);
    prev = cur;
  }
  if (can) puts("yes");
  else puts("no");
  return 0;
}

