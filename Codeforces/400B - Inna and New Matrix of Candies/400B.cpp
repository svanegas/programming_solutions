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

set <int> s;
string line;

int
main() {
    getline(cin, line);
    while (getline(cin, line)) {
        int posDuende = line.find("G");
        int posDulce = line.find("S");
        if (posDuende > posDulce) {
            puts("-1");
            return 0;
        }
        s.insert(posDulce - posDuende);   
    }
    cout << s.size() << endl;
	return 0;
}
