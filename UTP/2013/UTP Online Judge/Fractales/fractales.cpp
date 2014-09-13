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

double ini, act, mult, maxi;

int
main() {
    int t; cin >> t;
    while (t--) {
        cin >> act >> maxi;
        mult = double(5)/double(3);
        for (int i = 1; ; i++) {
            act *= mult;
            if (act > maxi) {
                cout << i-1 << endl;
                break;   
            }
        }
    }
    return 0;
}
