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
char ini;

string
voltear(int pos) {
    string res = orig.substr(pos, l - pos);
    res += orig.substr(0, pos);
    return res;
}

int
main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> l >> orig;
        str = final = orig;
        sort(str.begin(), str.end());
        ini = str[0];
        for (int i = 0; i < l; i++) {
            if (orig[i] == ini) {
                string possible = voltear(i);
                if (possible < final) {
                    ans = i;
                    final = possible;   
                }
            }   
        }
        cout << ans << endl;
    }
    return 0;
}
