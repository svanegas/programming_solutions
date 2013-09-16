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

string remp [2] = {"``", "''"};

int
main() {
    int it = 0;
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '"') {
                line.replace(i, 1, remp[it]);
                it = 1 - it;   
            }   
        }
        cout << line << endl;
    }
    return 0;
}
