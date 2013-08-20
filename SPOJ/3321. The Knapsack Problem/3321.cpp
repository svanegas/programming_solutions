/*  The Knaspack problem (Problema de la mochila)
    Programación dinámica */

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

const int MAXN = 2005;
const int MAXW = 2005;
int dp[MAXN][MAXW];
int n, w, a, b;
int tam[MAXN], v[MAXN];

int
main() {
    cin >> w >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        tam[i] = a;
        v[i] = b;
    }
    for(int col = 0; col <= w; col++) dp[0][col] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - tam[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-tam[i]] + v[i]);   
            }   
        }   
    }
    cout << dp[n][w] << endl;
    return 0;
}
