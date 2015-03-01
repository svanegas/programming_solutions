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

const int MAXN = 50005;
int student[MAXN];
int n;
long long m;
set <int> relig;

int
findd(int u) {
    if (student[u] == u) return u;
    return student[u] = findd(student[u]);
}

void
join(int u, int v) {
    int a = findd(u);
    int b = findd(v);
    if (a == b) return;
    student[a] = b;
}

int
main() {
    long long z = 1;
    while (cin >> n >> m && n) {
        relig.clear();
        for (int i = 0; i <= n; i++) student[i] = i;
        for (long long i = 0; i < m; i++) {
            int x1, x2;
            cin >> x1 >> x2;
            x1--; x2--;
            join(x1, x2);
        }
        for (int i = 0; i < n; i++) {
            relig.insert(findd(i));
        }
        cout << "Case " << (z++) << ": " << relig.size() << endl;
    }
    return 0;
}
