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

int n;

int
main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        //Espacios iniciales:
        for (int j = n - i; j > 0; j--) {
            cout << "  ";   
        }
        
        
        for (int j = 0; j <= i; j++) {
            if (j != 0) cout << " ";
            cout << j;   
        }
        for (int j = i-1; j >= 0; j--) {
            cout << " " << j;   
        }
        puts("");
    }
    for (int i = n-1; i >= 0; i--) {
        //Espacios iniciales:
        for (int j = n - i; j > 0; j--) {
            cout << "  ";   
        }
        
        for (int j = 0; j <= i; j++) {
            if (j != 0) cout << " ";
            cout << j;   
        }
        for (int j = i-1; j >= 0; j--) {
            cout << " " << j;   
        }
        puts(""); 
    }
	return 0;
}
