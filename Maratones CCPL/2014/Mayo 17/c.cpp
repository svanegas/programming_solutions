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

const int MAXN = 8;
int order[MAXN];
bool vva[MAXN];
int n, m, z = 1;
string tree;

void
readOrder() {
  getchar();
  scanf("x%d", &order[0]);
  for (int i = 1; i < n; i++) {
    scanf(" x%d", &order[i]); 
  }
}

char
query() {
  int low = 0, high = tree.size() - 1;
  for (int i = 0; i < n; i++) {
    int mid = low + (high - low) / 2;
    if (vva[order[i]-1]) low = mid + 1; 
    else high = mid;
  }
  return tree[low];
}

int
main() {
  while (cin >> n && n) {
    readOrder();
    cin >> tree;
    cin >> m;
    printf("S-Tree #%d:\n", (z++));
    for (int i = 0; i < m; i++) {
      string sVVA; cin >> sVVA;
      for (int j = 0; j < n; j++) vva[j] = (sVVA[j] == '1');
      cout << query();
    }
    cout << endl << endl;
  }
  return 0;
}
