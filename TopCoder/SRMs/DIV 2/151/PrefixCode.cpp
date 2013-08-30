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

class PrefixCode {
    public:
        string isOne(vector <string> words) {
            for (int i = 0; i < words.size(); i++) {
                string actual = words[i];
                for (int j = 0; j < words.size(); j++) {
                    string otra = words[j];
                    if (actual != otra && actual.size() <= otra.size()) {
                        if (actual == otra.substr(0, actual.size())) {
                            string ans = "No, ";
                            stringstream ss;
                            ss << i;
                            ans += ss.str();
                            return ans;
                        }
                    }   
                }
            }
            return "Yes";
        }    
};

int
main() {

    return 0;
}
