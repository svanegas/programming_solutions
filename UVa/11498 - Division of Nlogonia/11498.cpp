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

int k, x, y;

int
main() {
    while (cin >> k && k) {
        cin >> x >> y;
        while (k--) {
            int x1, y1;
            cin >> x1 >> y1;
            if (x1 == x || y1 == y) {
                cout << "divisa" << endl;
            }
            else if (x1 < x) {
                if (y1 < y) cout << "SO" << endl;
                else if (y1 > y) cout << "NO" << endl;
            }
            else {
                if (y1 < y) cout << "SE" << endl;
                else if (y1 > y) cout << "NE" << endl;
            }
        }
    }
    return 0;
}
