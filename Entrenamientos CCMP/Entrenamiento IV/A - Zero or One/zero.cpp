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
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == b && b == c) {
            cout << "*" << endl;
            continue;
        }
        if (a == b) cout << "C" << endl;
        if (b == c) cout << "A" << endl;
        if (a == c) cout << "B" << endl;
    }
    return 0;
}
