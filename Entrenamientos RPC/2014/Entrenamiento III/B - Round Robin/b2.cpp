#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;
int n, t;
vector <ll> jug;

void
sumar(ll valor, int ini, int fin) {
    for (int i = ini; i < fin; i++) {
        jug[i] += valor;   
    }
}

vector <ll>
voltear(int perdedor) {
    vector <ll> res;
    for (int i = perdedor + 1; i < n; i++) res.push_back(jug[i]);
    for (int i = 0; i < perdedor; i++) res.push_back(jug[i]);
    return res;
}

bool
iguales() {
    ll val = jug[0];
    for (int i = 0; i < n; i++) if (jug[i] != val) return false;
    return true;
}

int
main() {
    while (cin >> n && n) {
        cin >> t;
        jug.clear();
        for (int i = 0; i < n; i++) jug.push_back(0);
        while (true) {
            int pierde = (t + n - 1) % n;
            ll suma = t / n;
            if (pierde == n - 1) sumar(suma, 0, n);
            else {
                sumar(suma + 1, 0, pierde);
                sumar(suma, pierde + 1, n);  
            }
            jug = voltear(pierde);
            n = jug.size();
            if (iguales()) break;
        }
        cout << jug.size() << " " << jug[0] << endl;
    }
	return 0;
}
