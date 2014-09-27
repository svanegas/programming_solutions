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

map <char, string> enc;
map <string, char> decod;

string s;

void
build() {
  enc['A'] = ".-";  enc['B'] = "-..."; enc['C'] = "-.-."; enc['D'] = "-..";
  enc['E'] = ".";  enc['F'] = "..-."; enc['G'] = "--."; enc['H'] = "....";
  enc['I'] = "..";  enc['J'] = ".---"; enc['K'] = "-.-"; enc['L'] = ".-..";
  enc['M'] = "--";  enc['N'] = "-."; enc['O'] = "---"; enc['P'] = ".--.";
  enc['Q'] = "--.-";  enc['R'] = ".-."; enc['S'] = "..."; enc['T'] = "-";
  enc['U'] = "..-";  enc['V'] = "...-"; enc['W'] = ".--"; enc['X'] = "-..-";
  enc['Y'] = "-.--";  enc['Z'] = "--.."; enc['.'] = "---."; enc[','] = ".-.-";
  enc['?'] = "----"; enc['_'] = "..--";
  map <char, string> :: iterator it;
  for (it = enc.begin(); it != enc.end(); it++) {
    decod[it->second] = it->first; 
  }
}

int
main() {
  build();
  while (getline(cin, s)) {
    string msg = "";
    string nums = "";
    for (int i = 0; i < s.size(); i++) {
      string code = enc[s[i]];
      msg += code;
      nums += toStr(code.size());
    }
    reverse(nums.begin(), nums.end());
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
      int cant = toInt(nums[i]);
      string code = msg.substr(index, cant);
      index += cant;
      cout << decod[code];
    }
    puts("");
  }
  return 0;
}
