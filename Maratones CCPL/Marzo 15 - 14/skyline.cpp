using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl;

typedef long long ll;
const int MAXN = 10005;
int c, n, z;
vector <ll> height;
vector <ll> width;
int dpI[MAXN], dpD[MAXN];
ll distI[MAXN], distD[MAXN];

void
lis() { 
    dpI[0] = dpD[0] = 1;
    distI[0] = distD[0] = width[0];
    for (int i = 1; i < n; i++) {
        dpI[i] = dpD[i] = 1;
        distD[i] = distI[i] = width[i];
        for (int j = i - 1; j >= 0; j--) {
            if (height[j] < height[i]) {
                distI[i] = max(distI[i], width[i] + distI[j]);
                if (dpI[j] + 1 > dpI[i]) dpI[i] = dpI[j] + 1;
            }
            if (height[j] > height[i]) {
                distD[i] = max(distD[i], width[i] + distD[j]);
                if (dpD[j] + 1 > dpD[i]) dpD[i] = dpD[j] + 1;   
            }
            /*if (dpI[j] + 1 >= dpI[i] && height[j] < height[i]) {
                dpI[i] = dpI[j] + 1;
                distI[i] = max(distI[i], width[i] + distI[j]);
            }
            if (dpD[j] + 1 >= dpD[i] && height[j] > height[i]) {
                dpD[i] = dpD[j] + 1;
                distD[i] = max(distD[i], width[i] + distD[j]);
            }*/
        }   
    }
    ll maxI = distI[0], maxD = distD[0];
    for (int i = 0; i < n; i++) {
            maxI = max(maxI, distI[i]);
            maxD = max(maxD, distD[i]);
    }
    if (maxI >= maxD)
        printf("Case %d. Increasing (%lld). Decreasing (%lld).\n", (z++), maxI, maxD); 
    else
        printf("Case %d. Decreasing (%lld). Increasing (%lld).\n", (z++), maxD, maxI);
}

int
main() {
    cin >> c;
    z = 1;
    while (c--) {
        height.clear();
        width.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            height.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            width.push_back(x);
        }
        lis();
    }
    return 0;
}
