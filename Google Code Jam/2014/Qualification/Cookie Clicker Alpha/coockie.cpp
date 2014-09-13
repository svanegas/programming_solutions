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

int t;
double c, f, x, prod, tot;

int
main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> c >> f >> x;
        prod = 2.0;
        tot = 0.0;
        while (true) {
            if (x / prod <= ((c / prod) + (x / (prod + f)))) {
                tot += (x / prod);
                break;
            }
            else {
                tot += (c / prod);
                prod += f;   
            }
        }
        printf("Case #%d: %.7f\n", z, tot);
    }
	return 0;
}
