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

const int MAXN = 105;
int n, m;
vector <int> butt;
int apa[MAXN];

int
main() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) apa[i] = -1;
    for (int i = 0; i < m; i++) {
        int bi; cin >> bi;
        butt.push_back(bi);           
    }
    for (int i = 0; i < m; i++) {
        for (int j = butt[i]; j <= n; j++) {
            if (apa[j] == -1) apa[j] = butt[i];   
            else break;
        }   
    }
    cout << apa[1];
    for (int i = 2; i <= n; i++) cout << " " << apa[i];
    puts("");
	return 0;
}
