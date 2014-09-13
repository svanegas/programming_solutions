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

string line;

//Converts in range 1 - 3999
string
arabicToRoman(int num) {
  string uni[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  string deci[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string cen[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string mil[4] = {"", "M", "MM", "MMM"};
  int nUni = num % 10;
  int nDec = (num / 10) % 10;
  int nCen = ((num / 10) / 10) % 10;
  int nMil = (((num / 10) / 10) / 10) % 10;
  string ans = mil[nMil];
  ans += cen[nCen];
  ans += deci[nDec];
  ans += uni[nUni];
  return ans;
}

//Converts in range 1 - 3999
int
romanToArabic(string num) {
  map <char, int> RtoA;
  RtoA['I'] = 1;  RtoA['V'] = 5;  RtoA['X'] = 10; RtoA['L'] = 50;
  RtoA['C'] = 100;RtoA['D'] = 500;RtoA['M'] = 1000;
  
  int value = 0;
  for (int i = 0; num[i]; i++) {
    if (num[i+1] && RtoA[num[i]] < RtoA[num[i+1]]) {
      value += RtoA[num[i+1]] - RtoA[num[i]];
      i++; 
    }
    else value += RtoA[num[i]];
  } 
  return value;
}

int
main() {
  while(getline(cin, line)) {
    if (isdigit(line[0])) {
      cout << arabicToRoman(toInt(line)) << endl;
    }
    else {
      cout << romanToArabic(line) << endl;
    }
  }
  return 0;
}
