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

string s, t;
int val1, val2;

int
sum(int a, int b) {
  a += b;
  while (a >= 10) {
    int tmp = a;
    int res = tmp % 10;
    tmp /= 10;
    res += (tmp % 10);
    tmp /= 10;
    a = res + (tmp * 100);
  }
  return a;
}

int
main() {
  while (getline(cin, s)) {
    getline(cin, t);
    val1 = val2 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i])) {
        int val = tolower(s[i]) - 'a' + 1; 
        val1 = sum(val1, val);
      } 
    } 
    for (int i = 0; i < t.size(); i++) {
      if (isalpha(t[i])) {
        int val = tolower(t[i]) - 'a' + 1; 
        val2 = sum(val2, val);
      } 
    }
    double ans;
    if (val1 > val2)
      ans = val1 != 0 ? (val2 * 1.0 / val1 * 1.0) * 100.0 : 100.0;
    else
      ans = val2 != 0 ? (val1 * 1.0 / val2 * 1.0) * 100.0 : 100.0;
    printf("%.2f %%\n", ans);
  }
  return 0;
}
