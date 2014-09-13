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
        int f; cin >> f;
        unsigned long long sum = 0;
        for (int i = 0; i < f; i++) {
            unsigned long long s, a, v;
            cin >> s >> a >> v;
            sum += (s*v);
        }
        cout << sum << endl; 
    }
    return 0;
}
