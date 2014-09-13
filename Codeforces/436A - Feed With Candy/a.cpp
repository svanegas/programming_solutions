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

struct candy {
    int type, height, mass;
    
    candy(int t, int h, int m) {
        type = t; height = h; mass = m;
    }
    
    bool operator < (const candy &that) const {
      if (mass > that.mass) return true;
      if (mass == that.mass) {
          if (height < that.height) return true;
          else return false;
      }
      return false;
    }
};

const int MAXN = 2002;
int n, x;
vector <candy> v1;
vector <candy> v2;

int
main() {
  cin >> n >> x;
  int origX = x;
  for (int i = 0; i < n; i++) {
    int t, h, m;
    cin >> t >> h >> m;
    v1.push_back(candy(t, h, m));
    v2.push_back(candy(t, h, m));
  }
  
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  
  int turn = 0;
  int eaten = 0;
  for (int i = 0; i < v1.size(); i++) {
    candy c = v1[i];
    if (c.type == turn) {
      if (c.height <= x) {
        x += c.mass;
        turn = 1 - turn;
        v1.erase(v1.begin() + i);
        i = -1;
        eaten++;
        continue;
      }
    }
  }
  
  x = origX;
  turn = 1;
  int eaten2 = 0;
  for (int i = 0; i < v2.size(); i++) {
    candy c = v2[i];
    if (c.type == turn) {
      if (c.height <= x) {
        x += c.mass;
        turn = 1 - turn;
        v2.erase(v2.begin() + i);
        i = -1;
        eaten2++;
        continue;
      }
    }
  }
  cout << max(eaten, eaten2) << endl;
  return 0;
}
