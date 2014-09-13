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

bool can, duende;
priority_queue <int, vector<int>, greater<int> > q;
int n, m, dist, recorr, moves;

int
solve() {
    if (!can) return -1;
    recorr = 0;
    moves = 0;
    while (!q.empty()) {
        if (q.top() - recorr > 0) {
            recorr = q.top();
            moves++;   
        }   
        q.pop();
    }
    return moves;    
}

int
main() {
    cin >> n >> m;
    can = true;
    q = priority_queue <int, vector<int>, greater<int> >();
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        dist = 0;
        duende = false;
        for (int k = 0; k < m; k++) {
            if (line[k] == 'S') {
                if (!duende) can = false;
                else dist = k - dist;   
            } 
            else if (line[k] == 'G') {
                duende = true;
                dist = k;   
            }
        }
        q.push(dist);
    }
    cout << solve() << endl;
    return 0;
}
