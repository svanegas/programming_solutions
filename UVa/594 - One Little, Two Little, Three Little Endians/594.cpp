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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int num;
const int nBits = 32;

int
main() {
  while (cin >> num) {
    bitset<nBits> bits(num);
    bitset<nBits> bits2;
    int index = nBits - 1;
    for (int i = 1; i <= nBits / 8; i++) {
      for (int j = (8 * i) - 1; j >=  8 * (i - 1); j--) {
        bits2[index--] = bits[j]; 
      }
    }
    cout << num << " converts to " << (int)(bits2.to_ulong()) << endl;
  }
  return 0;
}
