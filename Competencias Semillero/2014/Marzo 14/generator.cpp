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

typedef long long ll;
const int MAXN = 500;
const int K = 50;
const ll maxX = 10000000;
map <ll, bool> m;
ll random;

int
main() {
    srand(time(NULL)); 
    cout << MAXN << " " << K << endl;
    random = rand();
    if (random < maxX * 2) assert (true);
    random = (random%(maxX)) ;
    m[random] = true;
    cout << random;
    for (int i = 1; i < MAXN; i++) {
        random = rand();
        if (random < maxX * 2) assert (true);
        random = (random%(maxX)) ;
        if (!m[random]) {
            m[random] = true;
            cout << " " << random;   
        }
        else i--;   
    }
    puts("");
    for (int i = 0; i < K; i++) printf("%d\n", random);
	return 0;
}
