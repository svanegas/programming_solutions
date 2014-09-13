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

int
fi(int n) {
    int result = n; 
    for(int i=2;i*i <= n;i++) { 
        if (n % i == 0) result -= result / i; 
        while (n % i == 0) n /= i; 
    } 
    if (n > 1) result -= result / n; 
    return result; 
} 
     
int
main() {
    int n;
    while (cin >> n) cout << fi(n)/2 << endl;
    return 0;   
}
