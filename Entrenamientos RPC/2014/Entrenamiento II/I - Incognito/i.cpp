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

int t, n;
map <string, int> m;

int
main() {
    cin >> t;
    while (t--) {
        cin >> n;
        m.clear();
        while (n--) {
            string nombre, tipo;
            cin >> nombre >> tipo;
            m[tipo]++;
        }
        int result = 1;
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            result *= (it->second + 1);
        }
        cout << result - 1 << endl;
    }
	return 0;
}
