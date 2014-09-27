//Just Code It.
using namespace std;
#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x "=" << (x) << endl

const double EPS = 1e-9;
typedef long long ll;

struct reg {
    int id;
    ll time, orig;

    reg (int ID, ll TIME, ll ORIG) : id(ID), time(TIME), orig(ORIG) {}

    bool operator > (const reg &r) const  {
        if (time > r.time) return true;
        else if (time == r.time) {
            if (id > r.id) return true;
            else return false;
        }
        else return false;
    }

    /*bool operator < (const reg &r) const  {
        if (time < r.time) return true;
        else if (time == r.time) {
            if (id < r.id) return true;
            else return false;
        }
        else return false;
    }*/
};

int main() {
    string s;
    priority_queue <reg, vector <reg>, greater <reg> > q;
    while (cin >> s && s != "#") {
        int id;
        ll r;
        cin >> id >> r;
        reg regObj = reg(id, r, r);
        q.push(regObj);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        reg next = q.top(); q.pop();
        cout << next.id << endl;
        next.time += next.orig;
        q.push(next);
    }
    return 0;
}
