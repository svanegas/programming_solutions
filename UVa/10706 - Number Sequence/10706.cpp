// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(T &x) {
  stringstream ss; ss << x; return ss.str();
}

typedef long long ll;

int t;

ll
len(int x) {
  return (ll) floor(1.0 + log10(x));
}

char
build(int limit, int needed) {
  string seq = "";
  for (int i = 1; seq.size() <= needed && i <= limit; ++i) seq += toStr(i);
  return seq[needed - 1];
}

int
main() {
  vector <ll> nums;
  nums.push_back(1LL);
  while (nums.back() < 2147483647LL) {
    int n = nums.size();
    nums.push_back(len(n + 1));
    nums[n] += nums[n - 1];
    nums[n] += (nums[n - 1] - (n - 2 >= 0 ? nums[n - 2] : 0LL));
  }
  scanf("%d", &t);
  while (t--) {
    ll x;
    scanf("%lld", &x);
    if (x == 1LL) printf("%lld\n", x);
    else {
      vector <ll> :: iterator low;
      low = lower_bound(nums.begin(), nums.end(), x);
      int pLow = low - nums.begin();
      cout << build(pLow + 1, (int) (x - nums[pLow - 1])) << endl;
    }
  }
  return 0;
}
