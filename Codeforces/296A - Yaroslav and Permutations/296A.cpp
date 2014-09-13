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

int n;
map <int, int> m;
int maxi;

int
main() {
    cin >> n;
    maxi = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        m[x]++;
        maxi = max(maxi, m[x]);   
    }
    if (n - maxi >= n / 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
