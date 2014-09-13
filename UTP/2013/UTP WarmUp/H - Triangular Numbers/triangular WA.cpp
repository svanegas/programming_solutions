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

int
main() {
    ull n;
    while (cin >> n && n) {
        long double sq = (8*(long double)n) + 1;
        if (sqrt(sq) * sqrt(sq) == sq) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
