#include <iostream>
#include <algorithm>
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
#include <stack>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) //cout << #x " = " << (x) << endl

using namespace std;



map <char, int> m;

template <class T> int toInt(const T&x) {
    stringstream s; s << x; int r; s >> r; return r;
}

vector <int> nums;

void
f() {
    int acum = 0;

    for(int i = 0; i < nums.size(); ++i){

        for(int j = i + 1; j < nums.size(); ++j){
            if(nums[i] > nums[j]) acum++;
        }
    }
    printf("Minimum exchange operations : %d\n", acum);
}

int
main() {
    int n;
    while (cin >> n) {
        nums.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nums.push_back(x);
        }
        f();
    }
    return 0;
}
