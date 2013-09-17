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

int
main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "1" || s == "4" || s == "78") {
            cout << "+" << endl;   
        }
        else if (s.substr(s.size()-2, 2) == "35") {
            cout << "-" << endl;   
        }
        else if (s[0] == '9' && s[s.size()-1] == '4') {
            cout << "*" << endl;   
        }
        else cout << "?" << endl;
    }
    return 0;
}
