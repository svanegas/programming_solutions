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

int n;
double totA, totB, sumA, sumB;

int
main() {
    cin >> n;
    totA = totB = sumA = sumB = 0.0;
    while (n--) {
        int ti, xt, yt;
        cin >> ti >> xt >> yt;
        if (ti == 1) {
            totA++;
            sumA += xt;
        }
        else {
            totB++;
            sumB += xt;
        }
    }
    if (sumA / totA >= 5.0) puts("LIVE");
    else puts("DEAD");
    if (sumB / totB >= 5.0) puts("LIVE");
    else puts("DEAD");
	return 0;
}
