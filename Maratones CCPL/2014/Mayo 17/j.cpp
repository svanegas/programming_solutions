using namespace std;
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <list>
#include <map>
#include <set>

//team550
//53763843

#define D(x) cout << #x " = " << (x) << endl

template <class T> string toStr(const T &x) {
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x) {
stringstream s; s << x; int r; s >> r; return r;
}

int n;

int main() {
    while (cin >> n && n) {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int cont = 0;
            for (int j = 0; j < 5; j++) {
                int xi; cin >> xi;
                cont += (xi >= 10);
            }
            if (cont >= 3) tot++;
        }
        cout << tot << endl;
    }
    return 0;
}
