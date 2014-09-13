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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

map <char, double> m;
int t;
string s;
double ans;

int
main() {
  m['C'] = 12.01;
  m['H'] = 1.008;
  m['O'] = 16.00;
  m['N'] = 14.01;
  cin >> t;
  while (t--) {
    cin >> s;
    char curr;
    int mult;
    ans = 0.0;
    for (int i = 0; i < s.size(); i++) {
      if (!isdigit(s[i])) {
        curr = s[i];
        if (i + 2 < s.size() && isdigit(s[i+1]) && isdigit(s[i+2])) {
          string num = "";
          num += s[i+1];
          num += s[i+2];
          mult = toInt(num);
          ans += (m[curr] * mult * 1.0);
          i += 2;
        }
        else if (i + 1 < s.size() && isdigit(s[i+1])) {
          string num = "";
          num += s[i+1];
          mult = toInt(num);
          ans += (m[curr] * mult * 1.0);
          i++;
        }
        else {
          ans += m[curr];
        }
      }
    }
    printf("%.3f\n", ans + EPS);
  }
  return 0;
}
