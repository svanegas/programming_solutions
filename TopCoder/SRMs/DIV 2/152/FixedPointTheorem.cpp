#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <float.h>
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

using namespace std;

class FixedPointTheorem {
    public:
        double f(double R, double X) {
            return R*X*(1-X);
        }
        
        double cycleRange(double R) {
            double X = f(R, 0.25);
            double mini = DBL_MAX;
            double maxi = DBL_MIN;
            for (int i = 0; i < 200000; i++) {
                X = f(R, X);
                if (X == 0.0) return 0.0;   
            }
            for (int i = 0; i < 1000; i++) {
                X = f(R, X);
                mini = min(mini, X);
                maxi = max(maxi, X);   
            }
            return maxi - mini;
        }
};

int
main() {

    return 0;
}
