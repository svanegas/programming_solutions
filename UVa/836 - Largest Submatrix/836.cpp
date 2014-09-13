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

const int MAXN = 30;
int t, n, m, maxi;
string line;
int arr[MAXN][MAXN];

int
main() {
    cin >> t; getchar(); getline(cin, line);
    while (t--) {
        int i = 0;
        while (getline(cin, line) && line != "") {
            m = line.size();
            for (int j = 0; j < line.size(); j++) {
                if (line[j] == '0') arr[i][j] = 0;
                else arr[i][j] = 1;
                if (i > 0) arr[i][j] += arr[i-1][j];
                if (j > 0) arr[i][j] += arr[i][j-1];
                if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];

            }
            i++;
        }
        n = i;
        maxi = 0;
        for (i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        int sub = arr[k][l];
                        if (i > 0) sub -= arr[i-1][l];
                        if (j > 0) sub -= arr[k][j-1];
                        if (i > 0 && j > 0) sub += arr[i-1][j-1];
                        int cas = (k - i + 1)*(l - j + 1);
                        //printf("En %d,%d a %d,%d hay %d\n", i, j, k, l, cas);
                        if (cas == sub) maxi = max(maxi, sub);
                    }   
                }   
            }  
        }
        cout << maxi << endl;
        if (t) cout << endl;
    }
	return 0;
}
