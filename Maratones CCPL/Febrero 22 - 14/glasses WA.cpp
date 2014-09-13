
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) cout << #x " = " << (x) << endl

using namespace std;

typedef unsigned long long ull;
const int MAXN = 1005;
ull fib[MAXN];
int n;

void
fibo () {
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < MAXN; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }
}

int
main() {
    int x;
    fibo();
    /*while (cin >> x) {
        cout << fib[x] << endl;
    }*/
    for (int i = 0; i < 1000; i++) cout << fib[i] << endl;
    return 0;
}
