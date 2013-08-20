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

int
main() {
    int c; cin >> c;
    while (c--) {
        unsigned long long a, b, res;
        res = a;
        cin >> a >> b;
        for (int i = 1; i < b; i++) {
            res *= a;
        }
        cout << res << endl;
    }
    return 0;
}
