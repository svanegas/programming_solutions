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
    double a, b;
    int z = 1;
    while (cin >> a >> b && a && b) {
        printf("Caso #%d: %d\n", z++, (int) ceil(sqrt(a*a + b*b)));
    }
    return 0;
}
