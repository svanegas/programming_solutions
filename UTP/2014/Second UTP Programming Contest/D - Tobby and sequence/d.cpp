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

int n;
vector <int> seq;

int
main() {
  while (cin >> n) {
    seq.clear();
    int num = n*2, diff = n, sign = 0;
    seq.push_back(num);
    for (int i = 1; i < n; i++) {
      if (sign == 0) seq.push_back(seq[i-1] - (diff--));
      else seq.push_back(seq[i-1] + (diff--));
      sign = 1 - sign;
    }
    cout << seq[0];
    for (int i = 1; i < n; i++) {
       cout << " " << seq[i];
    }
    cout << endl;
  }
  return 0;
}
