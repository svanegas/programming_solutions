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

int n;
map <char, bool> m, ignore;
string hist;

int
main() {
  while (cin >> n && n) {
    cin >> hist;
    m.clear();
    ignore.clear();
    int walked = 0, used = 0;
    for (int i = 0; i < hist.size(); i++) {
      if (ignore[hist[i]]) continue;
      if (m[hist[i]] == false) {
        if (used < n) {
          used++;
          m[hist[i]] = true; 
        }
        else {
          walked++;
          ignore[hist[i]] = true;
        }
      }
      else {
        used--;
        m[hist[i]] = false; 
      }
    }
    if (walked) printf("%d customer(s) walked away.\n", walked);
    else printf("All customers tanned successfully.\n");
  }
  return 0;
}
