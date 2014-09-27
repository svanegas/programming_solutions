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

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
set <ll> isSqrt;
ll x;
ll MAX = 5 * (1000000000000LL);

void
buildSqrt() {
    for (ll i = 0LL; i * i <= MAX; i++) isSqrt.insert(i*i);
}

bool
isSqrt2(ll a) {
    double sq = sqrt(a) + EPS;
    ll floorcito = (ll)(floor(sq));
    return floorcito * floorcito == a;
}

ll
getP() {
    for (ll p = 0LL; p * p <= x; ++p) {
        //if (isSqrt.count(x - (p*p))) return p;
        if (isSqrt2(x - (p*p))) return p;

    }
    return -1LL;
}

int
main() {
    //buildSqrt();
    int n;
    while (cin >> n) {
        ll count = 0LL;
        ll a, b, c, d;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c >> d;
            x = (a*a + b*b) * (c*c + d*d);
            ll p = getP();
            if (p != -1LL) {
                count++;
                cout << p << " " << (ll)(sqrt(x - (p*p)) + EPS) << endl;
            }
            else cout << "0 0" << endl;
        }
        cout << count << "/" << n << endl;
    }
    return 0;
}
