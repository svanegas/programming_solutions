using namespace std;

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
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define PI acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 100005;
int t, n, z = 1;

int
main() {
  cin >> t;
  int x=1;
  while (t--) {
    int nc;cin>>nc;
    int k,aux,ant;cin>>k;
    aux=k;
    ant=k;
    for(int i=1;i<nc;i++){
      int n;cin>>n;
      if((abs(n-ant))>aux){
        k=max((k+1),abs(n-ant));
        aux=k;
      }
      if((abs(n-ant))==aux)aux--;
      ant=n;
    }
    printf("Case %d: %d\n", x++, k);
  }
  return 0;
}
