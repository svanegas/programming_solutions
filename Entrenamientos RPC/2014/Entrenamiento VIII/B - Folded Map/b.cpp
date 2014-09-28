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

const int MAXN = 1005;
const int INF = 1 << 30;
int n, m, o, p;
int arr[MAXN][MAXN];
char line[MAXN];

int
main() {
  while (scanf("%d %d %d %d", &n, &m, &o, &p) != EOF) {
    scanf("%*c");
    for (int i = 0; i < n; i++) {
      scanf("%s", line);
      for (int j = 0; j < m; j++) {
        arr[i][j] = line[j] == 'X' ? 1 : 0;
        if (i > 0) arr[i][j] += arr[i-1][j];
        if (j > 0) arr[i][j] += arr[i][j-1];
        if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
      }
    }
    int mini = INF;
    for (int i = 1 - o, timesI = 0; timesI < o; i++, timesI++) {
      for (int j = 1 - p, timesJ = 0; timesJ < p; j++, timesJ++) {
        int used = 0;
        for (int u = i; u < n; u += o) {
          for (int v = j; v < m; v += p) {
            int k = u + o - 1, l = v + p - 1;
            int a, b, c, d;
            a = max(0, u), b = max(0, v);
            c = min(n-1, k); d = min(m-1, l);
            int inside = arr[c][d];
            if (a > 0) inside -= arr[a-1][d];
            if (b > 0) inside -= arr[c][b-1];
            if (a > 0 && b > 0) inside += arr[a-1][b-1];
            used += (inside > 0);
          }
        }
        mini = min(mini, used);
      }
    }
    printf("%d\n", mini);
  }
  return 0;
}
