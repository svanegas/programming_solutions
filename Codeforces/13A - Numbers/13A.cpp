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

int
fromDecimal2(int n, int b) {
    int result = 0; 
    while(n > 0) {
      result += n % b;
      n /= b;
    } 
    return result;
}

int
main() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 2; i <= n - 1; i++) {
        sum += fromDecimal2(n, i);
    }
    int gcd = __gcd((n)-2, sum);
    cout << (sum/gcd) << "/" << ((n)-2)/gcd << endl;
	return 0;
}
