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

const int MAXN = 2505;
int divi[MAXN];
int a;

int
divisors(int n) {
  if (divi[n] != -1) return divi[n];
  int tot = 0;
  int i;
  for (i = 1; i * 1 < n; i++) {
    if (n % i == 0) tot += 2;
  }  
  if (i * i == n) tot++;
  return tot;
}

int
main() {
  memset(divi, -1, sizeof divi);
  cin >> a;
  while (a--) {
    int xi, maxi = -1, ans = 1;
    cin >> xi; 
    for (int i = 1; i <= xi; i++) {
      int computedDiv = divisors(i);
      //printf("%d tiene %d\n", i, computedDiv);
      if (computedDiv > maxi) {
        ans = i;
        maxi = computedDiv;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
