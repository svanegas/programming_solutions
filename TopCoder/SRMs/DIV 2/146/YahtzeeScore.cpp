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

class YahtzeeScore {
    public:
        int maxPoints(vector <int> toss) {
            int maxi = 0;
            for (int i = 0; i < 5; i++) {
                int temp = toss[i];
                for (int j = i+1; j < 5; j++) {
                    if (toss[i] == toss[j]) {
                        temp += toss[j];
                    }   
                }
                maxi = max(maxi, temp);
            }
            return maxi;      
        }
};

int
main() {

    return 0;
}
