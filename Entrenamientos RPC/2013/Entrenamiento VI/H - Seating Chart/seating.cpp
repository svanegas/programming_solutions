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

const int MAXN = 100005;
map <string, int> m;
int mesa[MAXN];
int donde[MAXN];
int n;

int
f() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mesa[i] != i) {
            int don = donde[i];
            int val = mesa[i];
            swap(mesa[i], mesa[don]);
            donde[i] = i;
            donde[val] = don;
            ans++;
        }
    }
    return ans;   
}

int
main() {
    while (cin >> n && n) {
        m.clear();
        for (int i = 0; i < n; i++) {
            string man; cin >> man;
            m[man] = i;
        }
        for (int i = 0; i < n; i++) {
            string man; cin >> man;
            mesa[i] = m[man];
            donde[m[man]] = i;
        }
        cout << f() << endl;
    }
    return 0;
}
