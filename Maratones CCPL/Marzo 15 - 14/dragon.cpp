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
int n, m;
vector <ull> heads;
vector <ull> knights;

int
main() {
    while (cin >> n >> m && n && m) {
        heads.clear();
        knights.clear();
        for (int i = 0; i < n; i++) {
            ull x; cin >> x;
            heads.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            ull x; cin >> x;
            knights.push_back(x);
        }
        if (n > m) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        ull money = 0;
        bool sigCaso = false;
        int punt = 0;
        for (int i = 0; i < n; i++) {
            ull head = heads[i];
            while (punt < m && knights[punt] < head) {
                punt++;
            }
            if (punt < m) money += knights[punt++];
            else {
                puts("Loowater is doomed!");
                sigCaso = true;
                break;
            }
        }
        if (sigCaso) continue;
        else cout << money << endl;
    }
    return 0;
}
