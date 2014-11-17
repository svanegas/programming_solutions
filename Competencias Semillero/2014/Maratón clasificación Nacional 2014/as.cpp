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

int
main() {
  int n,k;
  while(cin>>n>>k && n && k){
    string number;
    cin>>number;
    int ans=0;
    int sizeT=(n-k-1);
    for(int i=0;i<number.size();i++){
      for(int j=i+1;j<number.size()-sizeT;j++){
        string compare=number[i]+number.substr(j,j+sizeT);
        ans = max(toInt(compare),ans); 
      }  
    }
    cout<<ans<<endl;
  }
  return 0; 
}
