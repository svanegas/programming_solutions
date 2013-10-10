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

const int MAXG = 6;
const int MAXE = 7;
int n, z = 1;
int g[MAXG] = {1, 2, 3, 3, 4, 10};
int e[MAXE] = {1, 2, 2, 2, 3, 5, 10};

int
main() {
    cin >> n;
    while (n--) {
        int contG = 0, contE = 0;
        for (int i = 0; i < MAXG; i++) {
            int x; cin >> x;
            contG += (x*g[i]);
        }
        for (int i = 0; i < MAXE; i++) {
            int x; cin >> x;
            contE += (x*e[i]);
        }
        if (contG < contE)
            printf("Battle %d: Evil eradicates all trace of Good\n", z++);
        else if (contE < contG)
            printf("Battle %d: Good triumphs over Evil\n", z++);
        else
            printf("Battle %d: No victor on this battle field\n", z++);
    }
    return 0;
}
