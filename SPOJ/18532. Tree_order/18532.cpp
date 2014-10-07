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

struct node {
  int left, right;
  node () : left(-1), right(-1) {}
};

const int MAXN = 8005;
node tree[MAXN];
int n, checkIndex = 0;
enum traversal {PRE, POST, IN};
int order[3][MAXN];
bool okayTree = true;

int
build_tree(int inLow, int inHigh, int postHigh) {
  if (inLow > inHigh) return -1;
  int root = order[POST][postHigh];
  int rootInd = -1;
  for (int i = inLow; i <= inHigh; ++i) {
    if (order[IN][i] == root) {
      rootInd = i;
      break; 
    }
  }
  if (rootInd == -1) {
    okayTree = false;
    return -1; 
  }
  tree[root].right = build_tree(rootInd + 1, inHigh, postHigh-1);
  if (!okayTree) return -1;
  tree[root].left = build_tree(inLow, rootInd - 1, postHigh-1-inHigh+rootInd);
  if (!okayTree) return -1;
  return root;
}

void
check_pre(int root) {
  if (root != order[PRE][checkIndex++]) okayTree = false;
  int left = tree[root].left;
  int right = tree[root].right;
  if (left != -1) {
    check_pre(left);
  }
  if (right != -1) {
    check_pre(right);
  }
}

int
main() {
  cin >> n;
  for (int i = PRE; i <= IN; ++i)
    for (int j = 0; j < n; ++j)
      cin >> order[i][j];
  build_tree(0, n - 1, n - 1);
  if (!okayTree) {
    cout << "no" << endl;
    return 0;
  }
  check_pre(order[POST][n-1]);
  if (!okayTree) {
    cout << "no" << endl;
    return 0;
  }
  cout << "yes" << endl;
  return 0;
}
