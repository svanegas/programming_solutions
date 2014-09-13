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

int maxi, mini;
int n;
bool dir;

int
main() {
    maxi = 10000000;
    mini = -10000000;
    cin >> n; n--;
    int prev; cin >> prev;
    while (n--) {
        int x1; cin >> x1;
        if (x1 - prev > 0) {
            //printf("voy de %d a %d en derecha\n", prev, x1);
            //printf("el maxi es:%d\n", maxi);
            mini = max(mini, prev);
            if (x1 > maxi) {
                //printf("como %d es mayor que el maxi:%d\n", x1, maxi);
                cout << "yes" << endl;
                return 0;   
            }
        }
        else {
            //printf("voy de %d a %d en izq\n", prev, x1);
            //printf("el mini es:%d\n", mini);
            maxi = min(maxi, prev);
            if (x1 < mini) {
                //printf("como %d es mayor que el mini:%d\n", x1, mini);
                cout << "yes" << endl;
                return 0;   
            }
        }
        prev = x1;
    }
    cout << "no" << endl;
	return 0;
}
