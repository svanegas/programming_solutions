#include <bits/stdc++.h>

using namespace std;

#define MAXN 300005
#define MOD 1000000007

typedef long long ll;
ll f[MAXN];

void build() {
  f[0] = 0LL;
  f[1] = 1LL;
  for (int i = 2; i < MAXN; ++i) {
    f[i] = f[i - 1] * 2LL;
    f[i] %= MOD;
  }
}

int main() {
  int n;
  ll m;
  build();
  while (cin >> n >> m) {
    int subSet = 0;
    string number;
    cin >> number;
    ll currNumber = 0LL;
    for (int i = 0; i < number.size(); ++i) {
      currNumber *= 10LL;
      currNumber += (number[i] - '0');
      currNumber %= m;
      if (currNumber == 0LL) subSet++;
    }
    if (currNumber == 0LL) cout << f[subSet] << endl;
    else cout << 0 << endl;
  }
}
