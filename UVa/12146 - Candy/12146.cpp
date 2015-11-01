#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
typedef long long ll;
vector <ll> nums[MAXN];
int n, m;

ll
findMaxSum(const vector <ll> &arr, int lim) {
  ll incl = arr[0];
  ll excl = 0LL;
  ll excl_new;
  for (int i = 1; i < lim; ++i) {
    excl_new = (incl > excl) ? incl : excl;
    incl = excl + arr[i];
    excl = excl_new;
  }
  return ((incl > excl) ? incl : excl);
}

int main() {
  while (cin >> n >> m && n) {
    vector <ll> caca;
    for (int i = 0; i < n; ++i) {
      nums[i].clear();
      for (int j = 0; j < m; ++j) {
        ll xi; cin >> xi;
        nums[i].push_back(xi);
      }
      caca.push_back(findMaxSum(nums[i], m));
    }
    cout << findMaxSum(caca, n) << endl;
  }
  return 0;
}
