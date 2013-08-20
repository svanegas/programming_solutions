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

int m, maxi;
string p;
vector <int> border;

int
borde() {
    maxi = 0;
    m = p.size();
    border = vector<int>(m);
    border[0] = 0;
    for (int i = 1; i < m; i++) {
        border[i] = border[i - 1];
        while (border[i] > 0 && p[i] != p[border[i]]) {
            border[i] = border[border[i] - 1];   
        }
        if (p[i] == p[border[i]]) {
            border[i]++;
            maxi = max(border[i], maxi);
        }
    }
    return maxi;
}

int
main() {
    while (getline(cin, p) && p != ".")  {
        cout << borde() << endl;
    }
    return 0;
}
