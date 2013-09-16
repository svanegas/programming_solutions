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
    int t, n, z = 1;
    while (cin >> t && t) {
        int bal = 0;
        while (t--) {
            cin >> n;
            if (n == 0) bal--;
            else bal++;
        }
        cout << "Case " << z++ << ": " << bal << endl;
    }
    return 0;
}
