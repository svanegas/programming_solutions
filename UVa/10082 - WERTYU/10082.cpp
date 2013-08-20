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

    char f1[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
                '-', '=', '!'};
    char f2[] = {'!', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[',
                ']', '\\'};
    char f3[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '!'};
    char f4[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
    char f5[] = {'!', '!', ' ', '!', '!'};
    map <char, char> m;
    
int
main() {
    for (int i = 1; i < sizeof(f1); i++) {
        m[f1[i]] = f1[i-1];
    }
    for (int i = 1; i < sizeof(f2); i++) {
        m[f2[i]] = f2[i-1];
    }
    for (int i = 1; i < sizeof(f3); i++) {
        m[f3[i]] = f3[i-1];
    }
    for (int i = 1; i < sizeof(f1); i++) {
        m[f4[i]] = f4[i-1];
    }
    m[' '] = ' ';
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            cout << m[line[i]];   
        }
        puts("");
    }
    return 0;
}
