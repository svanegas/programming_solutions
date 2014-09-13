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

typedef long long ll;
const int MAXN = 105;
int origN, n, t, pierde;
vector <ll> jug;

vector <ll>
voltear() {
    vector <ll> ret;
    for (int i = pierde+1; i < n; i++) ret.push_back(jug[i]);
    for (int i = 0; i < pierde; i++) ret.push_back(jug[i]);
    return ret;
}

bool
mismos() {
    ll val = jug[0];
    for (int i = 0; i < n; i++) if (jug[i] != val) return false;
    return true;
}

int
main() {
    while (cin >> origN && origN) {
        cin >> t;
        jug.clear();
        n = origN;
        for (int i = 0; i < n; i++) jug.push_back(0);
        while (true) {
            
            bool iguales = false;
            pierde = (t + n - 1) % n;
            if (pierde == n - 1) iguales = true;
            ll sum = t / n;
            if (iguales) {
                for (int i = 0; i < n; i++) jug[i] += sum;   
            }
            else {
                for (int i = 0; i <= pierde; i++) {
                    jug[i] += (sum+1);
                }
                for (int i = pierde+1; i < n; i++) {
                    jug[i] += sum;   
                }
            }
            
            jug = voltear();
            n = jug.size();
            if (mismos()) break;
        }
        cout << jug.size() << " " << jug[0] << endl;
    }
    return 0;
}
