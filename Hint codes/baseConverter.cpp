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

//Para pasar de decimal a cualquier base (hasta 20)
string
fromDecimal(int n, int b) {
   string chars = "0123456789ABCDEFGHIJ";
   string result = "";
   while (n > 0) {
      result = chars[n%b] + result;
      n /= b;
   }  
   return result;
}

//Para pasar de base menor que 10 a decimal
int
toDecimal(int n, int b) {
   int result=0;
   int multiplier=1;
   while (n > 0) {
      result += n%10*multiplier;
      multiplier *= b;
      n /= 10;
   }   
   return result;
}

int
main() {

	return 0;
}
