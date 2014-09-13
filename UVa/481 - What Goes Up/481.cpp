//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
int n;
ll x;
vector <ll> nums;

int
lis (ll dp[], int p[]) {
  ll longest = 1;
  int parent = 0;
  dp[0] = 1;
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    p[i] = -1;
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        p[i] = j;
        if (longest <= dp[i]) {
          longest = dp[i];
          parent = i;
        }
      }
    } 
  }
  cout << longest << endl << "-" << endl;
  vector <ll> seq;
  while (parent != -1) {
    seq.push_back(nums[parent]);
    parent = p[parent];
  }
  for (int i = seq.size() - 1; i >= 0; i--) cout << seq[i] << endl;
}

int
main() {
  ios::sync_with_stdio(false);
  while (cin >> x) {
    nums.push_back(x);
  }
  n = nums.size();
  if (n == 0) cout << "0" << endl << "-" << endl;
  else {
    ll dp[n];
    int p[n];
    lis(dp, p);
  }
  return 0;
}
