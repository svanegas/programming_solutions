#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 500005;
int n, c, arr[MAXN];
stack<int> s, ans;

void
clear_stack(stack<int> &st) {
  while (!st.empty()) st.pop();
}

int
main() {
  scanf("%d", &c);
  for (int z = 1; z <= c; ++z) {
    clear_stack(s); clear_stack(ans);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && s.top() <= arr[i]) s.pop();
      if (s.empty()) ans.push(-1);
      else ans.push(s.top());
      s.push(arr[i]);
    }
    printf("Case #%d:", z);
    for (int i = 0; i < n; ++i) {
      printf(" %d", ans.top());
      ans.pop();
    }
    puts("");
  }
  return 0;
}
