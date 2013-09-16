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

int i, p, s, t;

int
main() {
    int degree = 360/40;
    while (cin >> i >> p >> s >> t && (i || p || s || t)) {
        int ans = 120*degree;
        int temp = i - p;
        if (temp < 0) temp += 40;
        ans += temp*degree;
        temp = s - p;
        if (temp < 0) temp += 40;
        ans += temp*degree;
        temp = s - t;
        if (temp < 0) temp += 40;
        ans += temp*degree;
        cout << ans << endl;
    }
    return 0;
}
