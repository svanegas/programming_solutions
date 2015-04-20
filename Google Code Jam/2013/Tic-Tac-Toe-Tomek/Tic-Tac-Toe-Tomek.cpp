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

#define D(x) //cout << #x " = " << (x) << endl;

using namespace std;

typedef pair <int, int> pos;
const int MAXN = 4;
char board[MAXN][MAXN];
pos posibles[] = { pos(-1,-1), pos(-1,0), pos(-1,1), pos(0,-1),
                   pos(0,1), pos(1,-1), pos(1,0), pos(1,1) };
int c, z;
string linea;

bool
okay(pos sig) {
    int x = sig.first; int y = sig.second;
    return (y >= 0 && y < MAXN && x >= 0 && x < MAXN);
}

int
evaluar(pos actual) {
    for (int i = 0; i < 8; i++) {
        char simbolo = board[actual.first][actual.second];
        int sigX, sigY;
        sigX = posibles[i].first;
        sigY = posibles[i].second;
        pos sig = pos(actual.first + sigX, actual.second + sigY);
        //printf("Estoy en %d,%d y voy a ev %d,%d\n", actual.first,
                //actual.second, sig.first, sig.second);
        int cont = 1;
        while (okay(sig) && cont < 4) {
            //puts("Entro");
            if (board[sig.first][sig.second] == simbolo ||
                board[sig.first][sig.second] == 'T') {
                cont++;
                D(cont);
                sig = pos(sig.first + sigX, sig.second + sigY);
                //printf("Sigo con %d,%d\n", sig.first, sig.second);
                continue;
            }
            break;
        }
        if (cont == 4) return cont;
    }
    return 0;
}

int
main() {
    z = 1;
    cin >> c;
    while (c--) {
        getchar();
        printf("Case #%d: ", z++);
        for (int i = 0; i < MAXN; i++) {
            getline(cin, linea);
            for (int j = 0; j < MAXN; j++) {
                board[i][j] = linea[j];
            }   
        }
        int racha = 0;
        bool empty = false;
        for (int i = 0; i < MAXN; i++) {
            if (racha == 4) break;   
            for (int j = 0; j < MAXN; j++) {
                if (board[i][j] == '.') {
                    empty = true;
                    continue;
                }
                if (board[i][j] == 'T') continue;
                racha = evaluar(pos(i, j));
                if (racha == 4) {
                    printf("%c won\n", board[i][j]);
                    break;   
                }
            }
        }
        if (racha != 4) {
            if (empty) puts("Game has not completed");
            else puts("Draw");
        }
        
    }
    return 0;
}
