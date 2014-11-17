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
#include <time.h>

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
buscarN(ll x) {
    for (int i = 0; i < n; i++) {
        //printf("Busco en %d\n", i);
        if (array[i] == x) return i;
    }
    return -1;    
}

int
buscarLogNMio(ll x) {
    int lowIndex = 0;
    int highIndex = n-1;
    int midIndex = (lowIndex + highIndex) / 2;
    while (lowIndex <= highIndex) {
        //printf("Low: %d y hi: %d\n", lowIndex, highIndex);
        if (array[midIndex] == x) return midIndex;
        else if (array[midIndex] < x) lowIndex = midIndex + 1;
        else highIndex = midIndex - 1;
        midIndex = (lowIndex + highIndex) / 2;
    }
    return -1;
}

int
buscarLogN(ll x) {
    vector<ll> :: iterator low, up;
    low = lower_bound (array.begin(), array.end(), x); 
    return low - array.begin();  
}

int
main() {
    clock_t tStart = clock();
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        ll xi; 
        scanf("%lld", &xi);
        //cin >> xi;
        array.push_back(xi);
    }
    sort(array.begin(), array.end());
    /*for (int i = 0; i < q; i++) {
        printf("%lld\n", array[n/2]);   
    }
    return 0;*/
    //printf("El primer valor es: %lld y ult: %lld\n", array[0], array[n-1]);
    for (int i = 0; i < q; i++) {
        scanf("%lld", &k);
        //printf("En busca de %lld\n", k);
        //printf("%d\n", buscarN(k));
        //printf("%d\n", buscarLogN(k));
        printf("%d\n", buscarLogNMio(k));
    }
    //printf("Tiempo de ejecución: %f s\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
