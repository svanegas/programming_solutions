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

const int MAXN = 20005;
const int INF = 1 << 30;
int t, z, n;
int arr[MAXN];

int
main() {
    z = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        n--;
        for (int i = 0; i < n; i++) cin >> arr[i]; 
        int maxi = -1 * INF;
        int sum = 0;
        int iniR = 0;
        int finR = 0;
        int ini = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == maxi) {
                if (finR - iniR < i - ini) {
                    finR = i;
                    iniR = ini; 
                }   
            }
            else if (sum > maxi) {
                maxi = sum;
                finR = i;
                iniR = ini;
            }
            if (sum < 0) {
                sum = 0;
                ini = i+1;
            }
        }
        if (maxi > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", (z++), iniR+1, finR+2);
        else
            printf("Route %d has no nice parts\n", (z++));
    }
	return 0;
}
