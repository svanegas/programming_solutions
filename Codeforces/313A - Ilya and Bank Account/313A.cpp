#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

typedef long long ll;

int
main() {
    ll n, maxi, tmp, addi;
    n; cin >> n;
    maxi = n;
    tmp = n / 10;
    addi = n % 10;
    maxi = max(maxi, tmp);
    tmp /= 10;
    tmp = (tmp * 10) + addi;
    maxi = max(maxi, tmp);
    cout << maxi << endl;
}
