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

typedef long long ll;

int n;
map <ll, ll> m;
vector <ll> plants;

int binary(int l, int r, ll key) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    (plants[m] >= key ? r : l) = m;
  }
  return r;
}

int
main() {
  while (cin >> n) {
    plants.clear();
    m.clear();
    for (int i = 0; i < n; i++) {
      ll xi, ci; cin >> xi >> ci;
      plants.push_back(xi);
      m[xi] = ci;
    }
    sort(plants.begin(), plants.end());
    ll pos = plants[0];
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
      ll cover = plants[i] + m[plants[i]];
      int posAns = binary(i-1, n-1, cover);
      
      
      //printf("con %lld obtuve %d\n", plants[i], posAns - i);
      if (cover < plants[posAns]) posAns--; 
      int obten = posAns - i;
      if (obten > maxi) {
        maxi = obten;
        pos = plants[i]; 
      }
      /*for (int j = i + 1; j < n; j++) {
        if (plants[j] > cover) break;
        if (j - i > maxi) {
          maxi = j - i;
          pos = plants[i];
        }
      }*/
    }
    cout << pos << " " << maxi<< endl;
  }
  return 0;
}
