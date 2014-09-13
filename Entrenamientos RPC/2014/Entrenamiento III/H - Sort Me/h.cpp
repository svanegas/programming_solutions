#include <iostream>
#include <algorithm>
#include <iterator>
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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) cout << #x " = " << (x) << endl

//user: eafit123
//pass: sandiego123

using namespace std;

map <char, char> m;
int n;
string s;
vector <string> palabras;
map <string, string> toOrig;

int
main() {
    int z = 1;
    while (cin >> n && n) {
        cin >> s;
        m.clear();
        toOrig.clear();
        palabras.clear();
        int p = 65; // A
        for (int i = 0; i < s.size(); i++) m[s[i]] = char(p++);
        for (int i = 0; i < n; i++) {
            string xi; cin >> xi;
            string res = "";
            for (int j = 0; j < xi.size(); j++) {
                res += m[xi[j]];
            }
            palabras.push_back(res);
            toOrig[res] = xi;  
        }
        sort(palabras.begin(), palabras.end());
        printf("year %d\n", (z++));
        for (int i = 0; i < palabras.size(); i++) {
            cout << toOrig[palabras[i]] << endl;
        }
    }
    return 0;
}
