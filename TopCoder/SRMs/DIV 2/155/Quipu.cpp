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
#include <string.h>

using namespace std;

class Quipu {
    public:
        int readKnots(string knots) {
            istringstream ss(knots);
            string n;
            string ans = "";
            while (getline(ss, n, '-')) {
                int a = n.size();
                stringstream ss3;
                ss3 << a;
                ans += ss3.str();
            }
            cout << "ans: " << ans << endl;
            stringstream ss2;
            ss2 << ans;
            int x;
            ss2 >> x;
            return x;
        }
};

int
main() {

    return 0;
}
