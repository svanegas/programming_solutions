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
#include <iomanip>

/*a^n =
    -> 1, if n = 0
    -> a, if n = 1
    -> (a^(n/2))^2, if n is even
    -> (a^((n-1)/2)^2)*a, if n is odd
*/

using namespace std;

int
main () {
    double a;
    int n;
    while (cin >> a >> n && a) {
        double ret = 1;
        while (n) {
            if (n%2 == 1) {
                ret *= a;
            }
            a *= a;
            n /= 2;
        }
        printf("%.f\n", ret);
        cout << ret << endl; 
    }
}
