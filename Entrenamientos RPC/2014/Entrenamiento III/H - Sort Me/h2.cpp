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

map <char, char> m, orig;
vector <string> v;
int n;
string alien;

string
mapear(string s, map <char, char> m1) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        res += m1[s[i]];
    } 
    return res;   
}

int
main() {
    int year = 1;
    while (cin >> n && n) {
        v.clear();
        m.clear();
        orig.clear();
        cin >> alien;
        char actual = 'A';
        for (int i = 0; i < alien.size(); i++) {
            orig[actual] = alien[i];
            m[alien[i]] = (actual++);
        }
        for (int i = 0; i < n; i++) {
            string pal; cin >> pal;
            v.push_back(mapear(pal, m));
        }
        sort(v.begin(), v.end());
        printf("year %d\n", year++);
        for (int i = 0; i < v.size(); i++) {
            cout << mapear(v[i], orig) << endl;
        }
    }
	return 0;
}
