// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char
bec(char x) {
  if (x == '6') return '9';
  if (x == '9') return '6';
  if (x == '3' || x == '4' || x == '7') return 'z';
  return x;
}

bool
prime(ll n) {
  if (n == 1LL) return false;
  if (n == 2LL) return true;
  if (n % 2LL == 0LL) return false;
  for (ll i = 3LL; i * i <= n; i += 2LL) {
    if (n % i == 0LL) return false;
  }
  return true;
}

int
main() {
  string num; cin >> num;
  string res = "";
  bool can = prime(atoll(num.c_str()));
  for (int i = num.size() - 1; can && i >= 0; --i) {
    char next = bec(num[i]);
    if (next != 'z') res += next;
    else can = false;
  }
  if (can) {
    bool ans = prime(atoll(res.c_str()));
    printf("%s\n", ans ? "yes" : "no");
  }
  else puts("no");
  return 0;
}

