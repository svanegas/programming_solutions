using namespace std;
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define D(x) cout << #x " = " << (x) << endl;

const double EPS = 1e-9;

int n, k;
string num2;

string best1(string s){
  int n1 = s.size();
  for(int i = 0; i < n1-1; ++i){
    if(s[i] < s[i+1]){
      s.erase(s.begin()+i);
      return s;
    }
  }
  s.erase(s.begin()+ (n1 - 1));
  return s;
}

int
main() {
  while(cin >> n >> k && (n || k)){
    cin >> num2;
     while(k--){
      num2 = best1(num2);   
     }
     cout << num2 << endl;
  }
  return 0;
}
