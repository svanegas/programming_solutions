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

int n, m;
vector <int> dirty;

int
main() {
    cin >> n >> m;
    if (m == 0) {
        cout << "YES" << endl;
        return 0;   
    }
    while (m--) {
        int x; cin >> x;
        if (x == 1 || x == n) {
            cout << "NO" << endl;
            return 0;   
        }
        dirty.push_back(x); 
    }
    sort(dirty.begin(), dirty.end());
    int cont = 0;
    for (int i = 0; i < dirty.size() - 1; i++) {
        if(dirty[i+1] - dirty[i] > 1) cont = 0;
        else cont++;
        if (cont == 2) {
            cout << "NO" << endl;
            return 0;   
        }
    }
    cout << "YES" << endl;
	return 0;
}
