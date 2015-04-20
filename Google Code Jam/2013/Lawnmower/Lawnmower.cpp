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

const int MAXN = 105;
int c, z, n, m, p[MAXN][MAXN];

bool
evaluar(int i, int j) {
    int valor = p[i][j];
    int mArriba, mIzq;
    mArriba = mIzq = valor;
    bool ar, ab, iz, der;
    ar = ab = iz = der = false;
    
    //Arriba
    for (int k = i; k >= 0; k--) {
        if (p[k][j] > valor) {
            mArriba = p[k][j];
            ar = false;
            break;
        }
        if ((k == 0 && k != i)  && p[k][j] <= valor) ar = true;
    }
    
    //Abajo
    for (int k = i; k < n; k++) {
        if (p[k][j] > valor) {
            ab = false;
            break;
        }
        if ((k == n-1 && k != i)  && (p[k][j] <= valor)) {
            if (mArriba != valor) {
                if (p[k][j] >= mArriba) ab = true;
                else ab = false;   
            }
            else ab = true;
        }
    }
    
    //Izquierda
    for (int k = j; k >= 0; k--) {
        if (p[i][k] > valor) {
            mIzq = p[i][k];
            iz = true;
            break;
        }
        if ((k == 0 && k != j)  && p[i][k] <= valor) iz = true;
    }
    
    //Derecha
    for (int k = j; k < m; k++) {
        if (p[i][k] > valor) {
            der = false;
            break;
        }
        if ((k == m-1 && k != j)  && (p[i][k] <= valor)) {
            if (mIzq != valor) {
                if (p[i][k] >= mIzq) der = true;
                else der = false;   
            }
            else der = true;
        }
    }
    return ((ar && ab) || (iz && der));
    //return false;
}

int
main() {
    cin >> c;
    z = 1;
    while (c--) {
        printf("Case #%d: ", (z++)); 
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> p[i][j];
            }
        }
        if (m == 1 || n == 1) {
            puts("YES");
            continue;
        }
        bool centinela = true;
        for (int i = 0; (i < n && centinela); i++) {
            for (int j = 0; (j < m && centinela); j++) {
                if (!evaluar(i, j)) {
                    centinela = false;
                    break; 
                }
            }   
        }
        if (centinela) puts("YES");
        else puts("NO");
    }
    return 0;
}
