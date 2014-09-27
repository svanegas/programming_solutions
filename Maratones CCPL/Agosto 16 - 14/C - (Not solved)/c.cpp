//Just Code It.
using namespace std;
#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x "=" << (x) << endl
#define MAXN 100005
#define ll long long
#define INF 1000000005

const double EPS = 1e-9;

int t, n;
vector <ll> coins;

int binary(int l, int r, ll key) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    (coins[m] >= key ? r : l) = m;
  }
  if (coins[r] > key) return r - 1;
  return r;
}

int main(){
    cin >> t;
    while (t--) {
        coins.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll xi;
            cin >> xi;
            coins.push_back(xi);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            ll next = coins[i] * 2 - 1;
            int cont = 0;
            while (next != 0) {
                int index = binary(0, n-1, next);
                next -= coins[index];
                cont++;
            }
            maxi = max(maxi, cont);
        }
        cout << maxi << endl;
    }
    return 0;
}
