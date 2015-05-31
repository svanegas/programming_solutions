#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <class T> ll toLL(const T &x) {
  stringstream s; s << x; ll r; s >> r; return r;
}

template <class T> string toStr(const T &x) {
  stringstream s; s << x; return s.str();
}

const ll MAXN = 100000000000005LL;
vector <ll> d;
ll n;
int t;

ll
rev(ll x) {
  string cur = toStr(x);
  reverse(cur.begin(), cur.end());
  return toLL(cur);
}

void
bfs(ll s) {
  for (ll i = 0; i < MAXN; ++i) d.push_back(-1LL);
  puts("Hola");
  queue <ll> q;
  q.push(s);
  d[s] = 1LL;
  while (!q.empty()) {
    ll cur = q.front();
    q.pop();
    // Next number (step 1)
    ll next = cur + 1LL;
    if (next <= MAXN && d[next] == -1LL) {
      d[next] = d[cur] + 1LL;
      q.push(next);
    }
    // Reversing number
    next = rev(cur);
    if (next <= MAXN && d[next] == -1LL) {
      d[next] = d[cur] + 1LL;
      q.push(next);
    }
  }
}
int
main() {
  bfs(1LL);
  puts("YA");
  scanf("%d", &t);
  for (int z = 1; z <= t; ++z) {
    scanf("%lld", &n);
    printf("Case #%d: %lld\n", z, d[n]);
  }
  return 0;
}
