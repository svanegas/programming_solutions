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
int n, q;
ll k;
vector <ll> array;

int
buscarLogN(ll x) {
    int lowIndex = 0;
    int highIndex = n-1;
    int midIndex = (lowIndex + highIndex) / 2;
    while (lowIndex <= highIndex) {
        if (array[midIndex] == x) return midIndex;
        else if (array[midIndex] < x) lowIndex = midIndex + 1;
        else highIndex = midIndex - 1;
        midIndex = (lowIndex + highIndex) / 2;
    }
    return -1;
}

int
main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        ll xi; 
        scanf("%lld", &xi);
        array.push_back(xi);
    }
    sort(array.begin(), array.end());
    for (int i = 0; i < q; i++) {
        scanf("%lld", &k);
        printf("%d\n", buscarLogN(k));
    }
	return 0;
}
