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
    string line;
    int z = 1;
    while (getline(cin, line) && line != "*") {
        if (line == "Hajj") printf("Case %d: Hajj-e-Akbar\n", z++);
        else printf("Case %d: Hajj-e-Asghar\n", z++);
    }
    return 0;
}
