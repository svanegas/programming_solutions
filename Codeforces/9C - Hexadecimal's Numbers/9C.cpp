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

const int BASE = 2;
map <long long, int> m;
long long n;

long long
fromDecimal(long long n, int b) {
   long long result = 0;
   long long multiplier = 1;
      
   while (n > 0) {
      result += n%b*multiplier;
      multiplier *= 10;
      n /= b;
   } 
   return result;
}

int
main() {
    for (int i = 0; i <= 512; i++) { 
        long long bi = fromDecimal(i, BASE);
        m[bi] = i;
    }
    cin >> n;
    int anterior = 0;
    map<long long, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        long long value = it->first;
        if (n == value) {
            printf("%d\n", it->second);
            return 0;   
        }
        else if (n < value) {
            printf("%d\n", anterior);
            return 0;   
        }
        anterior = it->second;
    }
	return 0;
}
