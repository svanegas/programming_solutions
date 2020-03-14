#include <bits/stdc++.h>

using namespace std;

int n, d, sum;

int main() {
  cin >> n >> d;
  vector <int> nums;
  while (n--) {
    int x; cin >> x;
    sum += x;
    nums.push_back(x);
  }
  int val = d / sum;
  for (int i = 0; i < nums.size(); ++i) {
    cout << val * nums[i] << endl;
  }
  return 0;
}
