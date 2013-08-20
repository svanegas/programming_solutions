#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <map>

using namespace std;

const int MAXN = 55;
long long sec[MAXN];
int n;

int
main() {
    sec[0] = 1;
    sec[1] = 1;
    for(int i = 2; i <= MAXN; i++) {
        sec[i] = sec[i-1] + sec[i-2];   
    }
    while(cin >> n && n != 0) cout << sec[n] << endl;
    return 0;
}
