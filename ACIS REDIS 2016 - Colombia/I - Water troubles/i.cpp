// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1LL << 60;
const int MAXN = 7;
ll arr[MAXN], target;
int n;

/**
  The problem can be reduced to replacing arithmetic operations: +, -, *, / between a set of
  numbers and check if the result is greater or equal a target. Note that we can use one or more
  numbers in any order for the solution.
  Use recursive and bitmask approach, on each iteration, we check if we haven't included the ith
  number (hose) in the solution, if not, include it using the possible operators and recursively
  call the method again.

  - If a subtraction gives a negative number, prune the branch (not able to subtract more water than
  available).
  - If a division gives a non-integer number, prune the branch (not able to divide into non-integer
    numbers).
*/
ll
solve(int mask, ll acc) {
  ll mini = acc >= target ? acc : INF; // If current solution is greater or equal than target, use
                                       // it as current minimum, or use INF otherwise.
  for (int i = 0; i < n; ++i) { // Iterate through each number (hose)
    if (mask & (1 << i)) continue; // If ith number (hose) is already included in the solution, skip
    // Try adding the ith hose to the solution.
    mini = min(mini, solve(mask | (1 << i), acc + arr[i]));
    // If subtraction won't give negative number, try subtracting the ith hose to the solution.
    if (acc >= arr[i])
      mini = min(mini, solve(mask | (1 << i), acc - arr[i]));
    // Try multiplying the ith hose to the solution.
    mini = min(mini, solve(mask | (1 << i), acc * arr[i]));
    // If division won't give non-integer number, try dividing the ith hose to the solution.
    if (acc % arr[i] == 0)
      mini = min(mini, solve(mask | (1 << i), acc / arr[i]));
  }
  // Return the mini obtained.
  return mini;
}


int
main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  string line;
  while (getline(cin, line)) { // Read line by line
    n = 0;
    stringstream ss(line); ss >> target; // Get the target (first number in the line)
    if (target == 0LL) break;
    while (ss >> arr[n++]); // Store hose values in arr.
    n--; // Actually number of hoses.
    // Initially call the recursive method with mask 0 (haven't included any hose yet) and 0LL as
    // accumulated (no operation was performed yet).
    ll ans = solve(0, 0LL);
    printf("%lld\n", ans == INF ? 0LL : ans);
  }
  return 0;
}
