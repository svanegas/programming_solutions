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

const int MAXN = 100005;
int n, len;
set <char> diff[MAXN];

int
main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    len = s.size();
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != '?') diff[j].insert(s[j]);
    } 
  }
  for (int i = 0; i < len; i++) {
    if (diff[i].size() == 1) {
      cout << *diff[i].begin();
    }
    else if (diff[i].size() == 0) {
      cout << 'x';
    }
    else {
      cout << '?';
    }
  }
  puts("");
  return 0;
}
