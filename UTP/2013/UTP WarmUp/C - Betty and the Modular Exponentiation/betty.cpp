#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

typedef unsigned long long ull;
const ull modu = 1000000000;

int
modulo(ull a, ull b, ull c) {
    ull x = 1, y = a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y)%c;
        }
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}

int
main() {
    int t; cin >> t;
    while (t--) {
        ull a, b;
        cin >> a >> b;
        cout << modulo(a, b, modu) << endl;   
    }
    return 0;
}
