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

const int MAXN = 3002;
typedef pair<int, int> tree;
vector <tree> q;
int n, v;
bool nosee[MAXN];

int
main() {
  cin >> n >> v;
  memset(nosee, 0, sizeof(nosee));
  for (int i = 0; i < n; i++) {
    int day, cant;
    cin >> day >> cant;
    q.push_back(tree(day, cant)); 
  }
  sort(q.begin(), q.end());
  int day = 1;
  int tot = 0;
  int marked = 0;
  while (marked < n) {
    int llevo = 0;
    for (int i = 0; i < q.size(); i++) {
      if (nosee[i]) continue;
      if (llevo == v) break;
      if (q[i].first == day || q[i].first == day - 1) {
        int withdraw = min(v - llevo, q[i].second);
        llevo += withdraw;
        q[i].second -= withdraw; 
      }
      if (q[i].first < day - 1) {
        nosee[i] = true;
        marked++;
      }
    }
    day++;
    tot += llevo;
  }
  cout << tot << endl;
  return 0;
}
