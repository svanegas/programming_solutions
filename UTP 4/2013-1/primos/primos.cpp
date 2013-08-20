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

const int MAXN = 1000005;
bool primo[MAXN];
int cont;

void
primos() {
    for (int i = 0; i < MAXN; i++) primo[i] = false;
    primo[0] = true;
    primo[1] = true;
    for (int i = 4; i <= MAXN; i += 2) {
        primo[i] = true;   
    }
    for (int i = 3; i*i <= MAXN; i += 2) {
        if (!primo[i]) {
            for (int j = i*i; j <= MAXN; j += i) {
                primo[j] = true;   
            }   
        }   
    }
}

int
main() {
    primos();
    int a, b;
    while (cin >> a >> b && a != 0 && b != 0) {
        cont = 0;
        for (int i = a; i <= b; i++) {
            if (!primo[i]) cont++;
        }
        cout << cont << endl;
        /*int cont = 0;
        for (int i = a; i <= b; i++) {
            int primo = 1;
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    primo = 0;
                    break;
                }
            }
            if (primo == 1) cont++;
        }
        cout << cont << endl;*/
        
    }
    return 0;
}
