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
        string text, pattern;
        cin >> text >> pattern;
        if (text.find("T") == string::npos) {
            cout << "N" << endl;
            continue;   
        }
        if (text.find(pattern) != string::npos) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
