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
        if (s.size() == 5) {
            cout << 3 << endl;
            continue;
        }
        int cont = 0;
        if (s[0] == 'o') cont++;
        if (s[1] == 'n') cont++;
        if (s[2] == 'e') cont++;
        if (cont >= 2) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
