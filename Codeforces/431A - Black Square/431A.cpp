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

const int MAXN = 4;
int cal[MAXN];
string s;

int
main() {
  for (int i = 0; i < MAXN; i++) cin >> cal[i];
  cin >> s;
  int tot = 0;
  for (int i = 0; i < s.size(); i++) {
    string square = "";
    square += s[i];
    tot += cal[toInt(square)-1];
  }
  cout << tot << endl;
  return 0;
}
