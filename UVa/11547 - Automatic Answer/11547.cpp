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
        int x; cin >> x;
        x = (((((((x*567)/9)+7492)*235)/47)-498)/10);
        cout << abs(x%10) << endl;
    }
    return 0;
}
