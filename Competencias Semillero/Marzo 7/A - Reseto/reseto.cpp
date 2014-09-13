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

const int MAXN = 1005;
bool criba[MAXN];
int n, k;

bool
marcar(int i) {
    criba[i] = true;
    k--;
    return k == 0;
}

int
main() {
    memset(criba, 0, sizeof criba);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        if (!criba[i]) {
            for (int j = i; j <= n; j += i) {
                if (!criba[j])
                    if (marcar(j)) {
                        cout << j << endl;
                        return 0;   
                    }   
            }
        }
    }
	return 0;
}
