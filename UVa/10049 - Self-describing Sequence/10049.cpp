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

const int MAXN = 2000000000;
typedef pair<int, int> par;
vector <par> f;
int n;

int
binarySearch(int low, int high, int key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (f[mid].first > key) high = mid;
     else low = mid + 1;
  }
  if (f[high].first == key) return f[high].second;
  else {
    if (f[high].first < key) return f[high].second;
    else return f[high-1].second;
  }
}

int
main() {
  f.push_back(par(0, 0));
  f.push_back(par(1, 1));
  int pointer = 2, index = 2;
  while (index <= MAXN) {
    f.push_back(par(index, pointer));
    par p = f.back();
    int jump = binarySearch(1, f.size() - 1, pointer);
    index += jump;
    pointer++;
  }
  while (cin >> n && n) {
    printf("%d\n", binarySearch(1, f.size() - 1, n)); 
  }
  return 0;
}
