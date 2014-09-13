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

int n, zeros;

int
addDigit(int num, int digit) {
  return num * 10 + digit;
}

int
main() {
  while (cin >> n && n) {
    zeros = 0;
    int num1 = 0, num2 = 0;
    priority_queue <int, vector <int>, greater <int> > q;
    for (int i = 0; i < n; i++) {
      int xi; cin >> xi;
      if (xi) q.push(xi); 
      else zeros++;
    }
    num1 = addDigit(num1, q.top()); q.pop();
    num2 = addDigit(num2, q.top()); q.pop();
    int side = 1;
    for (int i = 0; i < zeros; i++) {
      if (side) num1 = addDigit(num1, 0);
      else num2 = addDigit(num2, 0);
      side = 1 - side;
    }
    while (!q.empty()) {
      if (side) num1 = addDigit(num1, q.top());
      else num2 = addDigit(num2, q.top());
      q.pop();
      side = 1 - side;
    }
    cout << num1 + num2 << endl;
  }
  return 0;
}
