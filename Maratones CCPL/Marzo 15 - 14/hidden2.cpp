using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
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

//157.253.238.31/boca/ team501

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl;

typedef long long ll;
typedef pair<string, int> par;
ll t;
int l, ans;
string orig, str, final;

string
voltear(const string &s) {
    string res = s.substr(1, s.size()-1);
    res += s[0];
    return res;
}

int
main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> l >> orig;
        final = orig;
        ans = 0;
        str = voltear(orig);
        int cont = 1;
        while (str != orig) {
            if (str < final) {
                final = str;
                ans = cont;   
            }
            str = voltear(str);
            cont++;
        }
        cout << ans << endl;
    }
    return 0;
}
