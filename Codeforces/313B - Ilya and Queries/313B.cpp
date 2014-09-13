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

const int MAXN = 100000;
int cant[MAXN];

int
main() {
    string s; cin >> s;
    cant[0];
    for (int i = 1; i < s.size(); i++) {
        cant[i] = (s[i] == s[i-1]) ? cant[i-1] + 1 : cant[i-1];   
    }
    int m; cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << cant[r] - cant[l] << endl;   
    }
    return 0;
}
