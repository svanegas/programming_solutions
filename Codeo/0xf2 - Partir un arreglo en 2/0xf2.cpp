#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 500005;
int n, sum[MAXN];

int
main() {
  cin >> n;
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < n; ++i) {
    cin >> sum[i];
    if (i > 0) sum[i] += sum[i - 1];
  }
  int left = 0, right = 0;
  for (int i = 1; i < n; ++i) {
    left = sum[i - 1];
    right = sum[n - 1] - sum[i - 1];
    if (left > 0 && right < 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}
