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

string pass;
bool up = false, low = false, dig = false, tam = true;

int
main() {
  cin >> pass;
  if (pass.size() < 5) tam = false;
  for (int i = 0; i < pass.size(); i++) {
    if (isupper(pass[i])) up = true;
    else if (islower(pass[i])) low = true;
    else if (isdigit(pass[i])) dig = true; 
  }
  if (up && low && dig && tam) puts("Correct");
  else puts("Too weak");
  return 0;
}
