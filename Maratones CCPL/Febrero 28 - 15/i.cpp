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



int
main() {
    int cases;
    cin >> cases;
    int x = 1;
    while (cases--){
        int n;
        cin >> n;
        ll acumMile, acumJuice, resultMile, resultJuice;
        acumJuice = acumMile = 0;
        for (int i = 0; i < n; ++i){
            double minutes;
            cin >> minutes;
            acumMile += ceil((minutes + 1)/30.0);
            acumJuice += ceil((minutes + 1)/60.0);  
        }
        resultMile = acumMile * 10;
        resultJuice = acumJuice * 15;
        if(resultMile == resultJuice) printf("Case %d: Mile Juice %lld\n", x++, resultMile);
        else if(resultMile < resultJuice) printf("Case %d: Mile %lld\n", x++, resultMile);
        else printf("Case %d: Juice %lld\n", x++, resultJuice);
    }
	return 0;
}
