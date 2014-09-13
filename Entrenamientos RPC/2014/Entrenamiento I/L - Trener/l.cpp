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

map<char, int> m;

int
main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        m[s[0]]++;
    }
    if (n < 5) {
        cout << "PREDAJA" << endl;
        return 0;  
    }
    string s = "";
    map <char, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second >= 5) s += it->first; 
    }
    if (s.size() == 0) {
        cout << "PREDAJA" << endl;
        return 0;  
    }
    sort(s.begin(), s.end());
    cout << s << endl;
	return 0;
}
