// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int p[MAXN], memo[MAXN][2];
int n, c;

// This top-down solution gives Runtime Error. Maybe stack overflow.
/*int
solve(int day, bool have) {
  int ans = 0;
  if (day == n) return ans;
  if (memo[day][have] != -1) return memo[day][have];
  if (have) {
    ans = max(ans, p[day] + solve(day + 1, false));
    ans = max(ans, solve(day + 1, true));
  }
  else {
    ans = max(ans, -(p[day] + c) + solve(day + 1, true));
    ans = max(ans, solve(day + 1, false));
  }
  return memo[day][have] = ans;
}*/

// Bottom-up approach according to above solution.
int
solve() {
  memo[n][false] = memo[n][true] = 0;
  for (int day = n - 1; day >= 0; --day) {
    memo[day][false] = max(0, -(p[day] + c) + memo[day + 1][true]);
    memo[day][false] = max(memo[day][false], memo[day + 1][false]);
    memo[day][true] = max(0, p[day] + memo[day + 1][false]);
    memo[day][true] = max(memo[day][true], memo[day + 1][true]);
  }
  return memo[0][false];
}

int
main() {
  while (scanf("%d %d", &n, &c) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    printf("%d\n", solve());
  }
  return 0;
}
