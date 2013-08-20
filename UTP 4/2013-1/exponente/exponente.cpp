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
    int n; cin >> n;
    while (n--) {
        unsigned long long b, e, r;
        cin >> b >> e;
        r = b;
        for (int i = 1; i < e; i++) {
            r *= b;
        }
        cout << r << endl;   
    }
    return 0;
}
