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

bool
borde(string &t, string &p) {
    int m;
    m = p.size();
    vector<int> border(m);
    border[0] = 0;
    for (int i = 1; i < m; i++) {
        border[i] = border[i - 1];
        while (border[i] > 0 && p[i] != p[border[i]]) {
            border[i] = border[border[i] - 1];   
        }
        if (p[i] == p[border[i]]) border[i]++;
    }
    int n;
    n = t.size();
    int seen = 0;
    for (int i = 0; i < n; i++) {
        while (seen > 0 && t[i] != p[seen]) {
            seen = border[seen - 1];   
        }
        if (t[i] == p[seen]) seen++;
        if (seen == m) return true;
    }
    return false;
}

int
main() {
    //ios::sync_with_stdio(false);
    int c;
    cin >> c;
    while (c--) {
        string t;
        int z;
        cin >> t >> z;
        while (z--) {
            string p;
            cin >> p;
            if (borde(t, p)) puts("y");
            else puts("n");
        }
    }
    return 0;
}
