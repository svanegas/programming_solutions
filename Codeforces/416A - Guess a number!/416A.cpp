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
const ll INF = 1LL << 60;
int n;
ll low, high;

int
main() {
  cin >> n;
  getchar();
  bool impossible = false;
  low = -INF;
  high = INF;
  while (n--) {
    string line, sign;
    char ans;
    ll number;
    getline(cin, line);
    stringstream ss(line);
    ss >> sign; ss >> number; ss >> ans;
    if (ans == 'N') {
      if (sign == ">") high = min(high, number); //<= 
      if (sign == "<") low = max(low, number); //>=
      if (sign == ">=") high = min(high, number - 1); // <
      if (sign == "<=") low = max(low, number + 1); // >
    }
    else {
      if (sign == ">") low = max(low, number + 1); 
      if (sign == "<") high = min(high, number - 1);
      if (sign == ">=") low = max(low, number);
      if (sign == "<=") high = min(high, number);
      
    }
    if (low > high) impossible = true;
  }
  if (impossible) puts("Impossible");
  else cout << max(low, -2000000000LL) << endl;
  return 0;
}
