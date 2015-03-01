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

typedef unsigned long long ull;
typedef pair<string, int> par;

ull t;
int l, ans;
string orig, str;
priority_queue <par, vector<par>, greater<par> > q;
priority_queue <par, vector<par>, greater<par> > realQ;

void
desalojar() {
    par inicial = q.top(); q.pop();
    realQ.push(inicial);
    while (!q.empty() && (q.top().first == inicial.first)) {
        par mismo = q.top();
        realQ.push(mismo);
        q.pop();
    }
    q = priority_queue <par, vector<par>, greater<par> >();
}

string
voltear(string s) {
    string res = s.substr(1, s.size()-1);
    res += s[0];
    return res;
}

int
main() {
    cin >> t;
    while (t--) {
        realQ = priority_queue <par, vector<par>, greater<par> >();
        q = priority_queue <par, vector<par>, greater<par> >();
        cin >> l >> orig;
        q.push(par(orig, 0));
        str = voltear(orig);
        int cont = 1;
        while (str != orig) {
            q.push(par(str, cont++));
            if (q.size() > 10000) desalojar();
            str = voltear(str);
        }
        while (!q.empty()) {
            par temp = q.top(); q.pop();
            realQ.push(temp);
        }
        string prim = realQ.top().first;
        ans = realQ.top().second;
        realQ.pop();
        while (!realQ.empty() && (realQ.top().first == prim)) {
            ans = min(ans, realQ.top().second);
            realQ.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
