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

#define D(x) //cout << #x " is " << (x) << endl;

using namespace std;

const long long MAXN = 100000000000005LL;
int c, z, cont;
long long a, b, maxi, ant;
//bool pal[MAXN];
map <long long, bool> pal;
map <long long, bool> visit;
string s;

string
aStr(long long x) {
    stringstream ss;
    ss << x;
    s = ss.str();
    return s;
}

long long
aInt(string x) {
    stringstream ss(x);
    long long u;
    ss >> u;
    return u;   
}

bool
dp(long long pali) {
    if (visit[pali]) return pal[pali];
    s = aStr(pali);
    char r, t;
    r = s[0];
    t = s[s.size()-1];
    string resto = s.substr(1, s.size()-2);
    if (resto != "") {
        //cout << "Con: " << pali << endl;
        pal[pali] = (r == t) && dp(aInt(resto));
        //puts("Salgo");
    }
    else if (r == t) pal[pali] = true;
    else pal[pali] = false;
    visit[pali] = true;
    return pal[pali];
}

int
main() {
    for (long long i = 0; i < 10; i++) {
        s = aStr(i);
        pal[i] = true;
    }
    cin >> c;
    z = 1;
    while (c--) {
        cin >> a >> b;
        printf("Case #%d: ", (z++));
        cont = 0;
        for (long long i = b; i >= a; i--) {
            //cout << "Calculo de " << i << endl;
            long long raiz = (long long) sqrt(i);
            if (raiz*raiz != i) {
                continue;
            }
            if (dp(i) && dp(raiz)) {
                cont++;
            }
        }
        cout << cont << endl;
    }
    return 0;
}
