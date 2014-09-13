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
long long cards[MAXN];
long long dp[2][MAXN];

int
main() {
    while (cin >> n) {
        memset(dp, 0, sizeof(long long)*n*2);    
        for (int i = 0; i < n; i++) {
            cin >> cards[i];   
        }
        int p = 1;
        for (int i = 1; i < n; i++) {
            if (p) {
                for (int j = 0; j < n - i; j++) {
                    dp[p][j] = max(dp[1-p][j] + cards[i+j], dp[1-p][j+1] + cards[j]);
                }
            }
            else {
                for (int j = 0; j < n - i; j++) {
                    dp[p][j] = min(dp[1-p][j], dp[1-p][j+1]);   
                }   
            }
            p = 1 - p;
        }
        cout << dp[1][0] << endl;
    }
    return 0;
}
