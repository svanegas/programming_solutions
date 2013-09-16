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

priority_queue <int> q;
int t;

int
main() {
    cin >> t;
    int z = 1;
    while (t--) {
        q = priority_queue <int>();
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            q.push(x);   
        }
        q.pop();
        printf("Case %d: %d\n", z++, q.top());
    }
    return 0;
}
