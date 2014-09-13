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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
const int MAXN = 100005;
int n;
int arr[MAXN];
vector <ll> factor;

int
main() {
    while (cin >> n) {
        factor.clear();
        factor.push_back(-1LL);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i > 0 && arr[i-1] > arr[i]) {
                factor.push_back(i-1);
            }
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 2) {
            cout << 2 << endl;
            continue;
        }
        if (factor[factor.size() - 1] != n - 1) factor.push_back(n-1);
        if (factor.size() <= 2) {
            cout << n << endl;
            continue;
        }
        ll maxi = -1LL;
        for (int i = 0; i < factor.size() - 2; i++) {
            maxi = max(maxi, factor[i+2] - factor[i]);
        }
        cout << maxi << endl;
    }
    return 0;
}
