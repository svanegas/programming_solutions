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

const int MAXN = 1045;
int f[MAXN];
int act[MAXN];
int n;
unsigned long long r;
//int iteraciones [MAXN][MAXN];
vector <vector <int> > iteraciones;

int
iterar() {
    int cont = 0;
    bool iguales = false;         
    while (!iguales) {
        iguales = true;
        vector <int> posiciones;
        for (int i = 1; i <= n; i++) {
            int pos = f[act[i]];
            act[i] = pos;
            //iteraciones[cont+1][i] = pos;
            posiciones.push_back(pos);
            if (pos != i) iguales = false;
        }
        iteraciones.push_back(posiciones);
        cont++;
    }
    return cont;
}

int
main() {
    while (cin >> n >> r) {
        iteraciones.clear();
        vector <int> ini;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            f[i] = x;
            act[i] = i;
            //iteraciones[0][i] = i;
            ini.push_back(i);
        }
        iteraciones.push_back(ini);
        if (r == 0) {
            cout << iteraciones[0][0];
            for (int i = 2; i <= n; i++) {
                cout << " " << iteraciones[0][i-1];   
            }   
        }
        else {
            int it = iterar();
            int j = r%it;
            cout << iteraciones[j][0];
            for (int i = 2; i <= n; i++) {
                cout << " " << iteraciones[j][i-1];   
            }
        }
        puts("");
    }
    return 0;
}
