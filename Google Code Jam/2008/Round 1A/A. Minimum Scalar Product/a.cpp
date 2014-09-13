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

const int MAXN = 805;
int t, n;
long long v1[MAXN];
long long v2[MAXN];
long long sum;

int
main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }   
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }
        sort(v1, v1+n);
        sort(v2, v2+n);
        for (int i = 0; i < n; i++) {
            sum += (v1[i] * v2[n-i-1]);  
        }
        printf("Case #%d: %lld\n", z, sum);
    }  
	return 0;
}
