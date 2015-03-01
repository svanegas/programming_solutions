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

int t, sum;
string s;

int
main() {
    cin >> t;
    while (t--) {
        sum = 0;
        stack <int> p;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\\') {
                p.push(i);
            }
            if (s[i] == '/') {
                if (!p.empty()) {
                    sum += (i - p.top());
                    p.pop();   
                }
            }
        }
        cout << sum << endl; 
    }
	return 0;
}
