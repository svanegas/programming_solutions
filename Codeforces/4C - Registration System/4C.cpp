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

map <string, pair <bool, int> > m;
int n;
string name;

int
main() {
    cin >> n;
    while (n--) {
        cin >> name;
        if (m[name].first) {
            cout << name << (m[name].second++) + 1 << endl;   
        }
        else {
            cout << "OK" << endl;
            m[name].first = true;   
        }
    }
	return 0;
}
