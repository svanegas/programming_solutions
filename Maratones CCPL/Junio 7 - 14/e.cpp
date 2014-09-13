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

string s1, s2;
bitset <1024> img1;
bitset <1024> img2;
int t, index1, index2;

void
build(int lvl, bool isImg1) {
  if ((isImg1 ? s1 : s2)[0] == 'p') {
    for (int i = 1; i <= 4; i++) {
      if (isImg1) s1.erase(0, 1);
      else s2.erase(0, 1);
      build(lvl-1, isImg1);
    }
  }
  else {
    if (isImg1) {
      int orig = index1;
      while (index1 < orig + ((1 << lvl) * (1 << lvl))) {
        img1[index1] = (s1[0] == 'f');
        index1++;
      }
    }
    else {
      int orig = index2;
      while (index2 < orig + ((1 << lvl) * (1 << lvl))) {
        img2[index2] = (s2[0] == 'f');
        index2++;
      } 
    }
  }
}

int
main() {
  cin >> t;
  while (t--) {
    cin >> s1 >> s2;
    index1 = index2 = 0;
    build(5, true);
    build(5, false);
    bitset <1024> result;
    result = img1 | img2;
    printf("There are %d black pixels.\n", result.count());
  }  
  return 0;
}
