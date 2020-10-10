/**
* O(n^3) Algorithm to find max subrectangle sum.
* The way it works is so beautiful, it uses Kadane's algorithm.
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const ll INF = 1LL << 60;
const int MAXN = 55;

int r, c;
ll m[MAXN][MAXN], arr[MAXN];

ll
kadane() {
  ll max_sum = -INF, sum = 0;
  for (int i = 0; i < r; ++i) {
    sum += arr[i];
    if (sum < 0) sum = 0;
    else if (sum > max_sum) max_sum = sum;
  }
  if (max_sum != -INF) return max_sum;
  else {
    for (int i = 0; i < r; ++i) max_sum = max(max_sum, arr[i]);
    return max_sum;
  }
}

void
find_max_sum() {
  ll sum, max_sum = -INF;
  for (int i = 0; i < r; ++i) {
    memset(arr, 0, sizeof(arr));
    for (int j = i; j < c; ++j) {
      for (int k = 0; k < r; ++k) arr[k] += m[k][j];
      max_sum = max(max_sum, kadane());
    }
  }
  printf("%lld\n", max_sum);
}

int
main() {
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) scanf("%lld", &m[i][j]);
  find_max_sum();
  return 0;
}
