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
vector <int> arr;
int n, m;

int
main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    arr.push_back(xi);
  }
  for (int i = 0; i < m; i++) {
    int key; cin >> key;
    vector<int>::iterator found = lower_bound(arr.begin(), arr.end(), key); 
    if (found != arr.end() && !(key < *found)) cout << (found - arr.begin()) + 1;
    else cout << "-1";
    if (i == m - 1) cout << endl;
    else cout << " ";
  }
  return 0;
}
