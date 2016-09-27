#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1LL << 60;
const int MAXN = 7;
ll arr[MAXN], target;
int n;

ll
solve(int mask, ll acc) {
  ll mini = acc >= target ? acc : INF;
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) continue;
    mini = min(mini, solve(mask | (1 << i), acc + arr[i]));
    if (acc >= arr[i])  // Can't output negative flow
      mini = min(mini, solve(mask | (1 << i), acc - arr[i]));
    mini = min(mini, solve(mask | (1 << i), acc * arr[i]));
    if (acc % arr[i] == 0) // Can't output non-integer flow
      mini = min(mini, solve(mask | (1 << i), acc / arr[i]));
  }
  return mini;
}


int
main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    n = 0;
    stringstream ss(line);
    ss >> target;
    if (target == 0LL) break;
    while (ss >> arr[n++]);
    n--;
    ll ans = solve(0, 0LL);
    printf("%lld\n", ans == INF ? 0LL : ans);
  }
  return 0;
}
