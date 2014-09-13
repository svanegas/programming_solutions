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

const int MAXN = 1003;
int n, p;
map <int, vector<int> > m;
map <int, int> donde;

int
main() {
    while (cin >> n && n) {
        cin >> p;
        m.clear();
        int pag = 0;
        for (int i = 1; i <= n/2; i++) {
            if (i % 2 == 1) pag++;
            m[pag].push_back(i);
            donde[i] = pag;
        }
        pag++;
        for (int i = (n/2) + 1; i <= n; i++) {
            if (i % 2 == 1) pag--;
            m[pag].push_back(i);
            donde[i] = pag;
        }
        vector <int> involucradas;
        for (int i = 0; i < m[donde[p]].size(); i++) {
            if (m[donde[p]][i] != p) involucradas.push_back(m[donde[p]][i]);
        }
        cout << involucradas[0] << " ";
        cout << involucradas[1] << " ";
        cout << involucradas[2] << endl;
    }
	return 0;
}
