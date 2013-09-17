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
    int tot = 0;
    while (n--) {
        string s; cin >> s;
        if (s == "donate") {
            int x; cin >> x;
            tot += x;
        }
        else {
            cout << tot << endl;   
        }
    }
    return 0;
}
