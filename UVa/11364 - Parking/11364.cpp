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

int c, xMax, xMin;
 
int
main() {
    cin >> c;
    while (c--) {
        int n; cin >> n;
        int x;
        xMax = -1; xMin = 100;
        for (int i = 0; i < n; i++) {
            cin >> x;
            xMax = max(xMax, x);
            xMin = min(xMin, x);
        }
        cout << (xMax-xMin)*2 << endl;
    }
    return 0;
}
