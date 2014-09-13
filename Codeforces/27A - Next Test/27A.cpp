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

vector <int> index;
int n;

int
main() {
    cin >> n;
    while (n--) {
        int x; cin >> x;
        index.push_back(x);
    }
    sort(index.begin(), index.end());
    if (index[0] != 1) {
        puts("1");
        return 0;   
    }
    for (int i = 1; i < index.size(); i++) {
        if (index[i] - index[i-1] > 1) {
            cout << index[i-1] + 1 << endl;
            return 0;   
        }
    }
    cout << index[index.size()-1] + 1 << endl;
	return 0;
}
