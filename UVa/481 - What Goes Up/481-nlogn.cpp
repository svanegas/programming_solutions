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
vector <ll> nums, dp;
vector <int> prev;

int
binarySearch(int low, int high, ll key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (nums[dp[mid]] > key) high = mid;
     else low = mid + 1;
  }
  return high;
}

void
lis() {
  prev[0] = -1;
  dp[0] = 0;
  int pointer = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[dp[0]]) { //Quiere empezar un nuevo lis
      prev[i] = -1;
      dp[0] = i;
    }
    else if (nums[i] > nums[dp[pointer-1]]) { //Me sirve como siguiente
      prev[i] = dp[pointer-1];
      dp[pointer++] = i;
    }
    else { //Quiere reemplazar un valor que ya había
      int donde = binarySearch(0, pointer-1, nums[i]);
      prev[i] = dp[donde-1];
      dp[donde] = i;
    }
  }
  vector <ll> seq;
  cout << pointer << endl << "-" << endl;
  int parent = dp[pointer-1];
  while (parent != -1) { 
    seq.push_back(nums[parent]);
    parent = prev[parent];
  }
  reverse(seq.begin(), seq.end());
  for (int i = 0; i < seq.size(); i++) {
    cout << seq[i] << endl; 
  }
}

int
main() {
  ll x;
  while (cin >> x) {
    nums.push_back(x);
    prev.push_back(-1);
    dp.push_back(0);
  }
  lis();
  return 0;
}
