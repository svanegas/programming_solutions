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

typedef long long ll;
int n, q;
ll k;
vector <ll> array;

int
buscarN(ll x) {
    for (int i = 0; i < n; i++) if (array[i] == x) return i;
    return -1;    
}

int
main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        ll xi; 
        scanf("%lld", &xi);
        array.push_back(xi);
    }
    sort(array.begin(), array.end());
    for (int i = 0; i < q; i++) {
        scanf("%lld", &k);
        printf("%d\n", buscarN(k));
    }
	return 0;
}
