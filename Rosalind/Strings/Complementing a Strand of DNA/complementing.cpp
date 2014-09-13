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

int c;
map <int, char> m;
vector <char> v;

int
main() {
  m[((int) 'C')] = 'G';
  m[((int) 'G')] = 'C';
  m[((int) 'A')] = 'T';
  m[((int) 'T')] = 'A';
  while ((c = getchar()) != EOF && c != '\n') {
    v.push_back(m[c]);
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i]; 
  }
  cout << endl;
  return 0;
}
