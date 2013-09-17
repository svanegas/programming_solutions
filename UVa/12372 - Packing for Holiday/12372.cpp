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
    int z = 1;
    while (n--) {
        int l, w, h;
        cin >> l >> w >> h;
        if (l > 20 || w > 20 || h > 20) {
            printf("Case %d: bad\n", z++);
            continue; 
        }
        else printf("Case %d: good\n", z++);
    }
    return 0;
}
