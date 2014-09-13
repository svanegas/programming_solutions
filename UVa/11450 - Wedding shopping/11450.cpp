#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXC = 25;
const int MAXM = 205;
int n, m, c, k;
bool dp[MAXM][MAXC];

void
limpiar() {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = false;   
        }   
    }    
}

int
main() {
    cin >> n;
    while (n--) {
        cin >> m >> c;
        //memset(dp, false, sizeof(bool) * (m+2) * (c+2));
        limpiar();
        for (int i = 0; i < c; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                int pj; cin >> pj;
                if (i == 0 && m-pj >= 0) dp[m-pj][i] = true;
                else
                    for (int l = m; l >= 1; l--)
                        if (dp[l][i-1] && l - pj >= 0) dp[l-pj][i] = true;
            }
        }
        int i;
        for (i = 0; i <= m; i++)
            if (dp[i][c-1]) break;
        if (i-1 == m) puts("no solution");
        else printf("%d\n", m-i);
    }
	return 0;
}
