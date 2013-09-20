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

const int MAXN = 1045;
int f[MAXN];
int act[MAXN];
bool visit[MAXN];
int original[MAXN];
int n;
unsigned long long r;

int
iterar(int pos) {
    if (visit[pos]) return 0;
    visit[pos] = true;
    return 1 + iterar(f[pos]);
}

void
actualizar(int pos, int inicial) {
    int next = f[original[pos]];
    original[pos] = next;
    if (next != inicial) actualizar(next, inicial);
    
}

int
main() {
    while (cin >> n >> r) {
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            f[i] = x;
            act[i] = i;
            visit[i] = false;
            original[i] = i;
        }
        if (r == 0) {
            cout << act[1];
            for (int i = 2; i <= n; i++) {
                cout << " " << act[i];   
            }
            puts("");
            continue;
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (!visit[i]) {
                    int j = iterar(i);
                    int demas = r%j;
                    for (int k = 0; k < demas; k++) {
                        actualizar(i, i);   
                    }
                }   
            }
        }
        cout << original[1];
        for (int i = 2; i <= n; i++) {
            cout << " " << original[i]; 
        }
        puts("");
    }
    return 0;
}
