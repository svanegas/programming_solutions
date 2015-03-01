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

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x) 
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x) 
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 500005;
const int MAXSQ = 1000;
vector <int> primes;
bool sieve[MAXSQ];
int sum[MAXN], b[MAXN];

void
build_sieve() {
    memset(sieve, false, sizeof sieve);
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i < MAXSQ; ++i) {
        if (!sieve[i]) {
            for (int j = i * i; j < MAXSQ; j += i) {
                sieve[j] = true;
            }
        }
    }
    //primes.push_back(1);
    for (int i = 2; i < MAXSQ; ++i) {
        if (!sieve[i]) primes.push_back(i);
    }
}

int
factorization(int a) {
    int ans = 0;
    int b = a;
    for (int i = 0; primes[i] * primes[i] <= a; ++i) {
        int p = primes[i];
        while (b % p == 0) {
            ans += p;
            b /= p;
        }
    }
    if (b != 1) ans += b;
    return ans;
}

int z, t, n, m;

int calc(int a) {
    if (sum[a] == a) return b[a] = 1;
    else return b[a] = (1 + calc(sum[a]));    
}

int
main() {
    z = 1;
    build_sieve();
    for (int i = 1; i < MAXN; ++i) {
        sum[i] = factorization(i);
    }
    sum[1] = 1;
    memset(b, -1, sizeof b);
    for (int i = 1; i < MAXN; ++i) if (b[i] == -1) calc(i);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int maxi = 0;
        for (int i = min(n, m); i <= max(n, m); ++i) {
            maxi = max(maxi, b[i]);   
        }
        printf("Case #%d:\n", z++);
        cout << maxi << endl;
    }
	return 0;
}
