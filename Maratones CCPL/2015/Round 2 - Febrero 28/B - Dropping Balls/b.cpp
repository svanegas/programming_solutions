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
#include <bitset>

#define D(x) cout << "DEBUG: " << #x " = " << x << endl;
#define ll long long

using namespace std;

ll a(ll value){
    double ans = (value - 1.0)/2.0;
    return (ll)ans;   
}

ll b(ll value){
    return ((value - 1 - a(value)));   
}

int
main() {
    int cases;
    cin >> cases;
    while(cases != -1){
        for(int i = 0; i < cases; ++i){
            int level;
            ll nactual = 1;
            ll nvalue;
            cin >> level >> nvalue;
            for(int i = 0; i < level - 1; ++i){
                if(nvalue % 2 == 0){
                    nactual = nactual*2 + 1;
                    nvalue = 1 + a(nvalue);  
                }else {
                    nactual*= 2;
                    nvalue = 1 + b(nvalue);
                }
            }
            cout << nactual << endl;
        }
        cin >> cases;
    }
	return 0;
}
