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

const int MAXN = 10005;
int n;
long long notas[MAXN];

int
main() {
    while (cin >> n) {
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> notas[i];
            tot += notas[i];
        }
        long long prom = tot/n;
        if (prom != double(tot)/double(n)) {
            cout << "-1" << endl;
            continue;   
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (notas[i] < prom) ans += (prom - notas[i]);
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}
