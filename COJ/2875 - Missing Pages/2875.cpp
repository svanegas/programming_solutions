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
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n, p;

int
main() {
  while (cin >> n && n) {
    cin >> p;
    vector <int> ans;
    ans.push_back(p % 2 ? p + 1 : p - 1);
    int group = ((p - 1) / 2) + 1;
    int adv, target;
    if (p > n / 2) {
      adv = n / 2 - group;
      target = 1 + adv;
    } 
    else {
      adv = group - 1;
      target = n / 2 - adv;
    }
    ans.push_back(target * 2);
    ans.push_back(target * 2 - 1);
    sort(ans.begin(), ans.end());
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    puts("");
  }
  return 0;
}
