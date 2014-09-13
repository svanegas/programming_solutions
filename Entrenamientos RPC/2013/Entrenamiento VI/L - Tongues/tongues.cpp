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

map <char, char> m;
string line;
                    
int
main() {
    m['a'] = 'e';
    m['i'] = 'o';
    m['y'] = 'u';
    m['e'] = 'a';
    m['o'] = 'i';
    m['u'] = 'y';
    
    m['b'] = 'p';
    m['k'] = 'v';
    m['x'] = 'j';
    m['z'] = 'q';
    m['n'] = 't';
    m['h'] = 's';
    m['d'] = 'r';
    m['c'] = 'l';
    m['w'] = 'm';
    m['g'] = 'f';
    m['p'] = 'b';
    m['v'] = 'k';
    m['j'] = 'x';
    m['q'] = 'z';
    m['t'] = 'n';
    m['s'] = 'h';
    m['r'] = 'd';
    m['l'] = 'c';
    m['m'] = 'w';
    m['f'] = 'g';
    
    while (getline(cin, line)) {
        string res = "";
        for (int i = 0; i < line.size(); i++) {
            bool up = isupper(line[i]);
            if (m.count(tolower(line[i])) == 0) {
                res += line[i];
            }
            else if (up) {
                char c = m[tolower(line[i])];
                char upper = toupper(c);
                res += upper;
            }
            else {
                res += m[line[i]];
            }
        }
        cout << res << endl;
    }
    return 0;
}
