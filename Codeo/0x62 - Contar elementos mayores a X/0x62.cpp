#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, c, x;

int
main() {
  cin >> n;
  vector <ll> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());
  cin >> c;
  while (c--) {
    cin >> x;
    vector<ll>::iterator low;
    // Binary search to find the place where the element x could be inserted
    // to keep non-decreasing order in the vector.
    low = upper_bound(v.begin(), v.end(), x);
    // Means that it is guaranteed that all elements before are less or equal
    // than x.
    cout << (v.end() - low) << endl;
  }
  return 0;
}
