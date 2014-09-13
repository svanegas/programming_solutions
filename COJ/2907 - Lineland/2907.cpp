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

typedef long long ll;
typedef pair <ll, ll> city;
int n;
vector <city> cities;

int
binarySearch(ll key) {
  int high = cities.size() - 1, low = 0;
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (cities[mid].first > key) high = mid;
     else low = mid + 1;
  }
  if (cities[high].first <= key) return high;
  else return high - 1;
}

int
main() {
  while (cin >> n) {
    cities.clear();;
    for (int i = 0; i < n; i++) {
      ll xi, ci;
      cin >> xi >> ci;
      cities.push_back(city(xi, xi + ci));
    }
    sort(cities.begin(), cities.end());
    int ans = -1, ansC = -1;
    for (int i = 0; i < n; i++) {
      int reaches = binarySearch(cities[i].second);
      if (reaches - i > ansC) {
        ansC = reaches - i;
        ans = i;
      }
    }
    cout << cities[ans].first << " " << ansC << endl;
  }
  return 0;
}
