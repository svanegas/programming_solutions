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

int maxn;

int
main() {
    string line;
    while (getline(cin, line)) {
        int num;
        maxn = 0;
        stringstream ss(line);
        int acum = 0;
        while (ss >> num) {
            acum += num;
            if (acum < 0) acum = 0;
            maxn = max(maxn, acum);
        }
        cout << maxn << endl;
    }
    return 0;
}
