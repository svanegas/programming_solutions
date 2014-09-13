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

typedef unsigned long long ull;
const int MAXN = 10;
bool esta[MAXN];
ull n;

bool
ya() {
    for (int i = 0; i < MAXN; i++) {
        if (!esta[i]) return false;   
    }
    return true;
}

void
contar(string s) {
    for (int i = 0; i < MAXN; i++) {
        char c = (char)(((int)'0')+i);
        if (s.find(c) != string::npos) esta[i] = true;
    }
}

int
main() {
    while (cin >> n) {
        memset(esta, false, sizeof(esta));
        for (ull i = 1; ;i++) {
            ull x = n*i;
            stringstream ss;
            ss << x;
            string str = ss.str();
            contar(str);
            if (ya()) {
                cout << i << endl;
                break;   
            }
        }
    }
    return 0;
}
