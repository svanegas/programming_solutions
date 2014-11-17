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

struct hole {
  int x, y;
  hole (int _x, int _y) : x(_x), y(_y) {}
  
  bool operator < (const hole &than) const {
    if (x < than.x) return true;
    else if (x == than.x) {
      return y < than.y;
    }
    else return false;
  }
  
  bool operator > (const hole &than) const {
    if (x > than.x) return true;
    else if (x == than.x) {
      return y > than.y;
    }
    else return false;
  }
};

const int MAXN = 1005;
int n;
char grille[MAXN][MAXN];
priority_queue <hole, vector <hole>, greater <hole> > q[2];

int
main() {
  while (cin >> n && n) {
    q[0] = priority_queue <hole, vector <hole>, greater <hole> >();
    q[1] = priority_queue <hole, vector <hole>, greater <hole> >();
    cin.ignore();
    int ind = 0;
    char c;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        c = getchar();
        if (c == 'O') {
          q[ind].push(hole(i, j));
        }
      }
      cin.ignore();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        grille[i][j] = getchar();
      }
      cin.ignore();
    }
    string message = "";
    for (int k = 0; k < 4; ++k) {
      q[1 - ind] = priority_queue <hole, vector <hole>, greater <hole> >();
      while (!q[ind].empty()) {
        hole next = q[ind].top(); q[ind].pop();
        message += grille[next.x][next.y];
        int auxX = next.x;
        next.x = next.y;
        next.y = (n - 1) - auxX;
        q[1 - ind].push(next);
      }
      ind = 1 - ind;
    }
    cout << message << endl;
  }
  return 0;
}
