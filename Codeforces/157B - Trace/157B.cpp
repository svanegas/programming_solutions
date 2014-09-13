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

double pi = 3.1415926535897932384626433832795;
int n;
priority_queue <int> q;
double tot;

int
main() {
    cin >> n;
    tot = 0;
    while (n--) {
        int x; cin >> x;
        q.push(x);
    }
    int sign = 1;
    while (!q.empty()) {
        int r = q.top(); q.pop();
        double sum = pi * (r*r); 
        tot += (sum * sign);
        sign *= -1;  
    }
    cout << tot << endl;
	return 0;
}
