// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
typedef long long ll;
int n;
ll h[MAXN];
stack <int> s;

ll
calc(int i) {
  int smallest = s.top(); s.pop();
  ll cur = h[smallest] * (s.empty() ? i : i - s.top() - 1); 
  return cur; 
}

ll
largest_rectangle() {
  ll ans = 0LL;
  int i = 0;
  while (i < n) {
    if (s.empty() || h[s.top()] <= h[i]) s.push(i++);
    else ans = max(ans, calc(i));
  }
  while (!s.empty()) ans = max(ans, calc(i));
  return ans;
}

int
main() {
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; ++i) scanf("%lld", &h[i]);
    printf("%lld\n", largest_rectangle());
  }
  return 0;
}

