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

class WidgetRepairs {
    public:
        int days(vector <int> arrivals, int numPerDay) {
            int ans = 0;
            for (int i = 0; i < arrivals.size(); i++) {
                if (i != arrivals.size()-1) {
                    if (arrivals[i] > 0) {
                        ans++;
                        int sumar = arrivals[i] - numPerDay;
                        if (sumar > 0)
                            arrivals[i+1] += (arrivals[i] - numPerDay);   
                    }
                }
                else {
                    double a = arrivals[i];
                    double b = numPerDay;
                    ans += ceil(a/b);
                }
            }
            return ans;
        }    
};

int
main() {

    return 0;
}
