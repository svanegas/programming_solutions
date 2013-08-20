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

const int MAXN = 100005;
vector<double> nume(MAXN);

int
main() {
    int n;
    while (cin >> n && n != 0) {
        nume.clear();
        for (int i = 0; i < n; i++) {
            double x;
            cin >> x;
            nume.push_back(x);
        }
        sort(nume.begin(), nume.begin()+n);
        if (n%2 == 1) {
            int r = n/2;
            printf("%.1lf\n", nume[r]);   
        }
        else {
            int r = (n/2) - 1;
            double res = (nume[r] + nume[r+1]) / 2;
            printf("%.1lf\n", res);
        }
    }
    return 0;
}
