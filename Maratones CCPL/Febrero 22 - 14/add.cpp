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

typedef unsigned long long ull;

int n;
priority_queue < ull, vector <ull>, greater<ull> > q;

int
main() {
    while (cin >> n && n) {
        q = priority_queue < ull, vector <ull>, greater<ull> >();
        while (n--) {
            ull x; cin >> x;
            q.push(x);   
        }
        int cost = 0;
        while (q.size() > 1) {
            ull sum;
            sum = q.top(); q.pop();
            sum += q.top(); q.pop();
            cost += sum;
            q.push(sum);   
        }
        cout << cost << endl;
    }    
    return 0;
}
