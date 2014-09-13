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

template <class T> double toDouble(const T &x)
{ stringstream s; s << x; double r; s >> r; return r; }

typedef long long ll;
const int MAXN = 105;
const ll INF = 1LL << 60;
ll d[MAXN][MAXN];
bool used[MAXN];

int
main() {
  int a, b, z = 1;
  while (cin >> a >> b && a && b) {
    for (int i = 0; i < MAXN; i++) {
      used[i] = false;
      for (int j = 0; j < MAXN; j++) {
        if (i == j) d[i][j] = 0LL;
        else d[i][j] = INF; 
      } 
    } 
    while (a != 0 && b != 0) {
      d[a][b] = 1LL;
      used[a] = used[b] = true;
      cin >> a >> b; 
    }
    
    for (int k = 1; k <= 100; k++) {
      if (!used[k]) continue;
      for (int i = 1; i <= 100; i++) {
        if (!used[i]) continue;
        for (int j = 1; j <= 100; j++) {
          if (!used[j]) continue;
          ll cand = d[i][k] + d[k][j];
          if (d[i][j] > cand) {
            d[i][j] = cand;
          }
        }
      }
    }
    
    ll sum, poss;
    sum = poss = 0LL;
    for (int i = 1; i <= 100; i++) {
      if (!used[i]) continue;
      for (int j = 1; j <= 100; j++) {
        if (!used[j]) continue;
        if (i != j) poss++;
        sum += d[i][j];
      }
    }
    
    double num = toDouble(sum);
    double den = toDouble(poss);
    double ans = num / den;
    printf("Case %d: average length between pages = %.3f clicks\n", z++, ans);
  }
  return 0;
}
