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

const int MAXN = 1000000;
bool criba[MAXN+5];

void
fill_criba() {
    memset(criba, false, sizeof(criba));
    
    criba[0] = criba[1] = true;
    for (int i = 4; i <= MAXN; i += 2) {
        criba[i] = true;   
    }
    for (int i = 3; i*i <= MAXN; i += 2) {
        if (!criba[i]) {
            for (int j = i*i; j <= MAXN; j+= i) {
                criba[j] = true;   
            }   
        }   
    }
}

int
main() {
    fill_criba();
    int a, b;
    while (cin >> a >> b && a && b) {
        int cont = 0;
        for (int i = a; i <= b; i++) {
            if (!criba[i]) cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
