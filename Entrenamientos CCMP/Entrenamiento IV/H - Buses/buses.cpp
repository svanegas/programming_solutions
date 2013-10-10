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

typedef unsigned long long ull;
ull mod = 1000000;
ull n, l, k, expo;

ull matrix_expo(ull n) {
    
    ull ans[2][2], m[2][2]={{0, 1}, {l%mod, k%mod}}, res[2][2] = {{0,1}, {l%mod, k%mod}};
    while (n) {
        if (n % 2 == 1) {
            memset(ans, 0, sizeof(ans));
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        ans[i][j] = (ans[i][j] + (res[i][k] * m[k][j])%mod)%mod;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    res[i][j] = ans[i][j];
                }
            }
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ans[i][j] = (ans[i][j] + (m[i][k] * m[k][j])%mod)%mod;
                }
            }
        }
        for (int i=0;i<2;i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = ans[i][j];
            }
        }
        n /= 2;
    }
    return res[1][1];
}

int
main() {
    unsigned long long n;
    while (cin >> n >> k >> l) {
        expo = (n/5) - 1;
        printf("%06llu\n", matrix_expo(expo));
    }
    return 0;
}
