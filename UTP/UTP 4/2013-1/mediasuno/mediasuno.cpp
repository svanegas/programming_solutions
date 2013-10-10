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
    int c; cin >> c;
    int z = 1;
    while (c--) {
        int k; cin >> k;
        int maxi = 0;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            maxi = max(maxi, x);
        }
        printf("Caso %d: %d %d\n", z++, k+1, maxi+1);
    }
    return 0;
}
