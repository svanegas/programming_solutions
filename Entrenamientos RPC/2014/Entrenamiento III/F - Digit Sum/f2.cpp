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

vector <int> nums;
string v[2];
int n, ceros, it;

int
main() {
    while (cin >> n && n) {
        nums.clear();
        v[0] = "";
        v[1] = "";
        ceros = 0, it = 0;
        for (int i = 0; i < n; i++) {
            int xi; cin >> xi;
            if (xi == 0) ceros++;
            else nums.push_back(xi);   
        }
        sort(nums.begin(), nums.end());
        v[0] += toStr(nums[0]);
        v[1] += toStr(nums[1]);
        nums.erase(nums.begin(), nums.begin() + 2);
        for (int i = 0; i < ceros; i++) {
            v[it] += "0";
            it = 1 - it;   
        }
        for (int i = 0; i < nums.size(); i++) {
            v[it] += toStr(nums[i]);
            it = 1 - it;   
        }
        cout << (toInt(v[0]) + toInt(v[1])) << endl;
    }
	return 0;
}
