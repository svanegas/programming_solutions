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

const int MAXN = 1005;
const int MAXK = 105;
int c, q, k, blusas, z = 1;
int color[MAXN];
bool usada[MAXN];

void
tacharColores (int col) {
    bool ya = false;
    for (int i = 1; i <= blusas && i < MAXN; i++) {
        if (color[i] == col) {
            usada[i] = true;
            ya = true;
        }
        else if (ya) return;
    }    
}

int
main() {
    while (cin >> c >> q >> k && c) {
        blusas = 0;
        int indi = 1;
        for (int i = 0; i < c; i++) {
            string col; cin >> col;
            int x; cin >> x;
            blusas += x;
            for (int j = 0; j < x; j++) {
                color[indi++] = i;
            }
        }
        printf("Caso #%d:\n", z++);
        for (int i = 0; i < q; i++) {
            vector <int> puestas;
            //memset(usada, false, sizeof(int)*blusas);
            memset(usada, false, sizeof(usada));
            string line;
            if (i == 0) getchar();
            getline(cin, line);
            stringstream ss(line);
            int x;
            while (ss >> x) {
                puestas.push_back(x);
            }
            for (int j = puestas.size() - 1; j >= puestas.size()-k && j >= 0; j--) {
                usada[puestas[j]] = true;
            }
            /*for (int j = 0; j < max(7,k); j++) {
                int x; cin >> x;
                puestas.push_back(x);
                if (j >= max(7,k) - k) {
                    usada[x] = true;
                }
            }*/
            if (puestas.size() - 7 >= 0) usada[puestas[puestas.size()-7]] = true;
            
            int anterior = puestas[puestas.size()-1];
            tacharColores(color[anterior]);
            //tacharColores(color[puestas[puestas.size()-1]]);
            
            vector <int> posibles;
            for (int i = 1; i <= blusas; i++) {
                if (!usada[i]) posibles.push_back(i);
            }
            
            if (posibles.size() == 0) puts("Comprar otra blusa");
            else {
                cout << posibles[0];
                for (int i = 1; i < posibles.size(); i++) {
                    cout << " " << posibles[i];   
                } 
                puts("");
            }
        }
        puts("");
    }   
    return 0;
}
