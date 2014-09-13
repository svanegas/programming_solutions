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

int n, k;

int
main() {
    cin >> n >> k;
    if (k > n) {
        cout << -1 << endl;
        return 0;   
    }
    if (k == 1) {
        if (n == 1) cout << "a" << endl;
        else cout << "-1" << endl;
        return 0;
    }
    string res = "";
    for (int i = k - 2; i > 0; i--) {
        res += (char)('a' + i + 1);
    }
    char prefix;
    int sign;
    if ((n - res.size()) % 2 == 0) {
        prefix = 'b';
        sign = 1;
    }
    else {
        prefix = 'a';
        sign = -1;
    }
    while (res.size() < n) {
        res += prefix;
        sign *= -1;
        prefix += sign;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
	return 0;
}
