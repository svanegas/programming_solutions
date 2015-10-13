#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct toy {
  ll s, p;
  double r;
  bool operator < (const toy &than) const {
    if (s < than.s) return true;
    else if (s == than.s) return p < than.p;
    else return false;
  }
};

vector <toy> toys_s;

int
main() {
  int n, k;
  int z = 1;
  while (scanf("%d %d", &n, &k) && k) {
    toys_s.clear();
    for (int i = 0; i < n; ++i) {
      toy t = toy();
      scanf("%lld %lld", &t.s, &t.p);
      t.r = (t.p * 1.0) / (t.s * 1.0);
      toys_s.push_back(t);
    }
    sort(toys_s.begin(), toys_s.end());
    ll firsts = 0LL;
    double ans = DBL_MAX;
    for (int i = 0; i < k - 1; ++i) firsts += toys_s[i].s;
    for (int i = k - 1; i < n; ++i) {
      toy cur = toys_s[i];
      double cand = ((firsts + cur.s) * 1.0) * cur.r;
      ans = min(ans, cand);
    }
    printf("Case #%d: %.6f\n", z++, ans);
  }
  return 0;
}
