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

const int tLimit = 210;

int
sig(int pos) {
    if (pos == 8) return 1;
    return pos+1;        
}

bool
next(char c) {
    if (c == 'T') return true;
    return false;   
}

int
main() {
    int pos; cin >> pos;
    int n; cin >> n;
    int total = 0;
    bool solved = false;
    for (int i = 0; i < n; i++) {
        int time;
        char ans;
        cin >> time >> ans;
        if (!solved) {
            total += time;
            if (total < tLimit) {
                if (next(ans)) {
                    pos = sig(pos); 
                }
                continue;
            }
            if (total >= tLimit) {
                cout << pos << endl;
                solved = true;
            }
        }
    }
	return 0;
}
