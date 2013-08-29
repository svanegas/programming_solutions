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

using namespace std;

class DivisorDigits {
    public:
        int howMany(int number) {
            int n = number;
            bool ans[10];
            int rpt = 0;
            memset(ans, false, sizeof(ans));
            while (n > 0) {
                int k = n%10;
                n /= 10;
                if (k && (number/k)*k == number) {
                    rpt++;
                }   
            }
            return rpt;
        }
};

int
main() {

    return 0;
}
