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
    int n, c;
    string s;
    while (cin >> c && c) {
        double max = 0.0;
        string ans1 = "";
        int ans2 = 0;
        while (c--) {
            cin >> s >> n;
            string tempS = s;
            int tempN = n;
            double ret = 1;
            a = atof(s.c_str());
            while (n) {
                if (n%2 == 1) {
                    ret *= a;
                }
                a *= a;
                n /= 2;
            }
            if (ret > max) {
                max = ret;
                ans1 = tempS;
                ans2 = tempN;
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
}
