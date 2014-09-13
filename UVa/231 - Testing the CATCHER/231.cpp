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

vector <int> missiles;
vector <int> dp;

int
lis() {
    int maxi = 1;
    for (int i = 0; i < missiles.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (missiles[j] < missiles[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                maxi = max(maxi, dp[i]);
            }   
        }   
    }  
    return maxi; 
}

int
main() {
    int xi, z = 1;
    while (cin >> xi && xi != -1) {
        if (z > 1) cout << endl;
        missiles.clear();
        dp.clear();
        missiles.push_back(xi);
        dp.push_back(1);
        int xii;
        while (cin >> xii && xii != -1) {
            missiles.insert(missiles.begin(), xii);  
            dp.push_back(1); 
        }
        printf("Test #%d:\n", (z++));
        printf("  maximum possible interceptions: %d\n", lis());
        
    }
	return 0;
}
