#include <iostream>
#include <algorithm>
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
#include <bitset>

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n;

int
main() {
    while (cin >> n) {
        priority_queue <int> q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        bool can = true;
        while (!q.empty()) {
            int next = q.top(); q.pop();
            if (q.size() < next) {
                can = false;
                break;
            }
            vector <int> edges;
            for (int i = 0; i < next; i++) {
                int xi = q.top(); q.pop();
                edges.push_back(xi - 1);
            }
            for (int i = 0; i < next; i++) {
                if (edges[i] == 0) continue;
                q.push(edges[i]);
            }
        }
        if (can) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}
