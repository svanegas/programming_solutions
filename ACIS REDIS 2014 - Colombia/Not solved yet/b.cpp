#include <iostream>
#include <algorithm>
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
#include <bitset>

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 5;
int arr[MAXN][MAXN];

bool
solve(vector <vector<int> > mat, vector <int> nums) {
    if (nums.size() == 0) {
        for (int i = 0; i < mat.size(); i++) {

        }
    }
    can = false;
    for (int i = 0; i < nums.size(); i++) {
        vector <int> next;
        for (int j = 0; j < nums.size() - 1; j++) {
            if (j == i) continue;
            next.push_back(nums[j]);
        }
        can &= solve()
    }
}

int
main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int x;
        vector <int> nums;
        int sum = 0;
        while (ss >> x) {
            sum += x;
            nums.push_back(x);
        }
        int sz = nums.size() / 2;
        if (sz * 2 == nums.size()) {
            if (nums.size() == 16 && sum % 4 != 0) {
                cout << "N" << endl;
                continue;
            }
            else if (nums.size() == 9 && sum % 3 != 0) {
                cout << "N" << endl;
                continue;
            }
            else if (nums.size() == 4 && sum % 2 != 0) {
                cout << "N" << endl;
                continue;
            }
            vector <vector <int> > row;
            for (int i = 0; i < sz; i++) {
                vector <int> col;
                row.push_back(col);
                for (int j = 0; j < sz; j++) {
                    row[i].push_back(0);
                }
            }
            if (solve(row, nums)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
        else cout << "N" << endl;
    }
    return 0;
}
