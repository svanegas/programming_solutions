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

#define D(x)// cout << #x " = " << (x) << endl;

const double EPS = 1e-9;

int n, k, acum;

string num;

int
main() {
  //ios::sync_with_stdio(false);
  while(cin >> n >> k && (n || k)){
    cin >> num;
    acum = 0;
    for(int i = 0; i < num.size()-1 && acum < k; ++i){
      D(i);
      if(num[i] < num[i+1]){
        num.erase(num.begin()+i);
        if(i) i--;
        i--;
        //cout << "i vale" << i;
        acum++;
      }
    }
    if(acum < k){
      num = num.substr(0, n - k);
    }
    cout << num << endl;
  }
  return 0;
}
