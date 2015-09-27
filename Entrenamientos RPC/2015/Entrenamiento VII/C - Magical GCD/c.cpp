#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
typedef long long ll;
int t, n;
ll nums[MAXN];

ll
magic(int a, int b) {
	int len = b - a + 1;
	if (len == 1) return nums[a];
	ll cur = __gcd(nums[a], nums[a + 1]);
	for (int i = a + 2; i <= b; ++i) {
		cur = __gcd(nums[i], cur);
	}
	return cur * len;
}

int
main() {
  puts("TLE");
  return 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lld", &nums[i]);
		ll maxi = 0LL;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				maxi = max(maxi, magic(j, i));
			}
		}
		printf("%lld\n", maxi);
	}
	return 0;	
}
