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

int t, sumX, sumNum;
string eq, lefteq, righteq;

void
read() {
  int i = 0;
  cin >> eq;
  lefteq = righteq = "";
  while (eq[i++] != '=') lefteq += eq[i-1];
  while (i++ < eq.size()) righteq += eq[i-1];
}

void
addSigns() {
  if (lefteq[0] != '-') lefteq = "+" + lefteq;
  if (righteq[0] != '-') righteq = "+" + righteq;
}

void
processLeft() {
  sumX = sumNum = 0;
  int i = 1;
  while (i < lefteq.size()) {
    int sign = (lefteq[i-1] == '+' ? 1 : -1);
    bool x = false; string num = "";
    while (i < lefteq.size() && lefteq[i] != '-' && lefteq[i] != '+') {
      if (isdigit(lefteq[i])) num += lefteq[i];
      else {
        if (num == "") num = "1";
        x = true;
      }
      i++;
    }
    if (x) sumX += (toInt(num) * sign);
    else sumNum += (toInt(num) * sign * -1);
    i++;
  }
}

void
processRight() {
  int i = 1;
  while (i < righteq.size()) {
    int sign = (righteq[i-1] == '+' ? 1 : -1);
    bool x = false; string num = "";
    while (i < righteq.size() && righteq[i] != '-' && righteq[i] != '+') {
      if (isdigit(righteq[i])) num += righteq[i];
      else {
        if (num == "") num = "1";
        x = true;
      }
      i++;
    }
    if (x) sumX += (toInt(num) * sign * -1);
    else sumNum += (toInt(num) * sign);
    i++;
  }
}

int
main() {
  cin >> t;
  while (t--) {
    read();
    addSigns();
    processLeft();
    processRight();
    if (sumX == sumNum && sumX == 0) puts("IDENTITY");
    else if (sumX == 0 && sumNum != 0) puts("IMPOSSIBLE");
    else printf("%d\n", (int)floor((sumNum * 1.0) / (sumX * 1.0)));
  }
  return 0;
}
