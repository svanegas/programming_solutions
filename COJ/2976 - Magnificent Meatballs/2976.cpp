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

const int MAXN = 35;
int n;
int table[MAXN];

int
main() {
  while (cin >> n && n) {
    for (int i = 1; i <= n; i++) cin >> table[i];
    int i = 1, j = n, sumS = table[i], sumE = table[j];
    while (j - i > 1) {
      if (sumS > sumE) {
        j--;
        sumE += table[j]; 
      }
      else {
        i++;
        sumS += table[i]; 
      }
    }
    if (sumS != sumE) puts("No equal partitioning.");
    else printf("Sam stops at position %d and Ella stops at position %d.\n", i, j);
  } 
  return 0;
}
