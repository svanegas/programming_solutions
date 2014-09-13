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

#define D(x) //cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int a, b, orA, orB, maxi, sum;
unsigned int n;

int
main() {
    while (scanf("%d %d", &a, &b) != EOF) {
        maxi = 0;
        orA = a;
        orB = b;
        if (a > b) swap(a, b);
        for (int i = a; i <= b; i++) {
            sum = 1;
            n = i;
            D(n);
            while (n != 1) {
                if (n % 2 == 1) n = 3*n + 1;
                else n /= 2;
                sum++;
            }
            if (sum > maxi) maxi = sum;
        }
        printf("%d %d %d\n", orA, orB, maxi);
    }
	return 0;
}
