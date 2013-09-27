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
    int n, l, c;
    while (cin >> n >> l >> c) {
        int contPag = 1;
        int contChar = 0;
        int contLine = 1;
        for (int i = 0; i < n; i++) {
            string pal; cin >> pal;
            if (contChar + pal.size() + 1 <= c + 1) contChar += pal.size() + 1;
            else {
                contLine++;
                contChar = pal.size() + 1;
                if (contLine > l) {
                    contPag++;
                    contLine = 1;
                } 
            }            
        }
        cout << contPag << endl;
    }
    return 0;
}
