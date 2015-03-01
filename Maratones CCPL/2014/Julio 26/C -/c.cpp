using namespace std;

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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define PI acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n;

vector <int>
partir(vector <int> v, int pos) {
  vector <int> ret;
  ret.insert(ret.begin(), v.begin() + pos + 1, v.end());
  ret.insert(ret.end(), v.begin(), v.begin() + pos);
  return ret;
}

bool
solve(vector <int> v, int m) {
  if (v.size() == 1) {
    if (v[0] == 13) return true;
    else return false;
  }
  if (v[m % v.size()] == 13) return false;
  v = partir(v, m % v.size());
  solve(v, m);
}

int
main() {
  while (cin >> n && n) {
    vector <int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);
    for (int i = 1; i <= n; i++) {
        nums = partir(nums, i-1);
        if (solve(nums, i-1)) {
          cout << i << endl;
          break;
        }
    }
  }
  return 0;
}
