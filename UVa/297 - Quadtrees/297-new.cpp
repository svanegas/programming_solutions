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

int c, i;
string tree1, tree2;
bitset <1024> img1, img2;

void
drawTree1(int level) {
  if (tree1[0] == 'p') {
    for (int i = 0; i < 4; i++) {
      tree1.erase(0, 1);
      drawTree1(level - 1);
    }
  }
  else if (tree1[0] == 'e') {
    i += ((1 << level) * (1 << level));
  }
  else {
    for (int orig = i; i < orig + (1 << level) * (1 << level); i++) {
      img1[i] = 1; 
    }
  }
}

void
drawTree2(int level) {
  if (tree2[0] == 'p') {
    for (int i = 0; i < 4; i++) {
      tree2.erase(0, 1);
      drawTree2(level - 1);
    }
  }
  else if (tree2[0] == 'e') {
    i += ((1 << level) * (1 << level));
  }
  else {
    for (int orig = i; i < orig + (1 << level) * (1 << level); i++) {
      img2[i] = 1; 
    }
  }
}

int
main() {
  cin >> c;
  while (c--) {
    img1.reset(); img2.reset();
    cin >> tree1 >> tree2;
    i = 0;
    drawTree1(5);
    i = 0;
    drawTree2(5);
    printf("There are %d black pixels.\n", (img1 | img2).count());
  }
  return 0;
}
