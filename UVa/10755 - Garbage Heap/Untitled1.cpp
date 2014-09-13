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
#include <time.h>

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int
main() {
    srand(time(NULL)); 
    int n = 3;
    int m = 3;
    int o = 3;
    //puts("1\n");
    //printf("%d %d %d\n", n, m, o);
    cin >> n >> n >> m >> o;
    puts("1\n");
    printf("%d %d %d\n", n, m, o);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                //long long r = rand();
                //int s = rand()%2;
                //if (s == 1) cout << r*-1;
                //else cout << r;
                //if (i == n - 1 && j == m - 1 && k == o - 1) cout << "";
                //else cout << " ";
                long long x; cin >> x;
                cout << x/1000;
                if (i == n - 1 && j == m - 1 && k == o - 1) cout << "";
                else cout << " ";
                
            }   
        }   
    }
    puts("");
	return 0;
}
