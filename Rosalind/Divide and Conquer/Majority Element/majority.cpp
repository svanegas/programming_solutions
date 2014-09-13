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

typedef pair <int, int> par;
int k, n;
map <int, int> m;

int
main() {
  cin >> k >> n;
  while (k--) {
    m.clear();
    for (int i = 0 ; i < n; i++) {
      int xi; cin >> xi;
      m[xi]++;
    }
    priority_queue <par> q;
    map <int, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
      int num = it->first; 
      int times = it->second;
      q.push(par(times, num));
    }
    if (q.top().first > n / 2) cout << q.top().second;
    else cout << "-1";
    if (k) cout << " ";
    else cout << endl;
  }
  return 0;
}
