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

long long cIni, cArr, cPun, ans = 0;
bool ini = true, arr = false, pun = false;

int
main() {
  string s; cin >> s;
  s += '$';
  for (int i = 0; i < s.size(); i++) {
    if (ini) {
      if (isalpha(s[i])) cIni++;
      else if (isdigit(s[i]) || s[i] == '_') {}
      else if (s[i] == '@') {
        ini = false;
        arr = true; 
        cArr = 0;
      }
      else cIni = 0;
    }
    else if (arr) {
      if (isdigit(s[i]) || isalpha(s[i])) cArr++;
      else if (s[i] == '@' || s[i] == '_') {
        i -= cArr + 1;  
        arr = false;
        ini = true;
        cIni = 0; 
      }
      else if (s[i] == '.' && cArr > 0) { //Es un punto
        arr = false;
        pun = true;
        cPun = 0;
      }
      else {
        arr = false;
        ini = true;
        cIni = 0; 
      }
    }
    else if (pun) {
      if (isalpha(s[i])) {
        cPun++; 
      }
      else {
        ans += (cIni * cPun);
        i -= cPun + 1;
        pun = false;
        ini = true;
        cIni = 0;
        cPun = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
