#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN = 50005;

int n, c, p, q;
ll sum[MAXN];

int
main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> sum[i];
    if (i > 0) sum[i] += sum[i - 1];
  }
  cin >> c;
  while (c--) {
    cin >> p >> q;
    if (p > 0) cout << sum[q] - sum[p - 1];
    else cout << sum[q];
    cout << endl;
  }
  return 0;
}
