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

int n, a, b;

int
main() {
    while (cin >> n >> a >> b) {
        int cont = 1;
        if (a%2 == 1) a++;
        if (b%2 == 1) b++;
        while (abs(a-b) > 1) {
            a /= 2;
            b /= 2;
            if (a%2 == 1) a++;
            if (b%2 == 1) b++;
            cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
