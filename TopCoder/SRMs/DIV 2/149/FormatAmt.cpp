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

class FormatAmt {
    public:
        string amount(int dollars, int cents) {
            stringstream ss;
            stringstream ss2;
            ss << dollars;
            string ans1 = "";
            string ans2 = "";
            ss2 << cents;
            if (cents < 10) {
                ss2 >> ans2;
                ans2 = ".0" + ans2;
            }
            else {
                ss2 >> ans2;
                ans2 = "." + ans2;
            }
            cout << ans2;
            string doll = ss.str();
            int cont = 1;
            for (int i = doll.size()-1; i >= 0; i--) {
                ans1 = doll[i] + ans1;
                if (cont%3 == 0 && i != 0) ans1 = "," + ans1;
                cont++;
            }
            ans1 = "$" + ans1;
            ans1 += ans2;
            return ans1;
        }    
};

int
main() {

    return 0;
}
