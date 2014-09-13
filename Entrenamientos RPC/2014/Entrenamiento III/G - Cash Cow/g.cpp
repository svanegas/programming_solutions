#include <iostream>
#include <algorithm>
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
#include <stack>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) cout << #x " = " << (x) << endl

using namespace std;

typedef pair <int, int> par;

int n = 12;
int m = 10;
int t, visitados;
char tab[12][10];
bool visit[12][10];

void
bfs(int ii2, int jj2) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            visit[i][j] = false;
    if (tab[ii2][jj2] == '.') return;
    queue <par> q;
    q.push(par (ii2, jj2));
    visit[ii2][jj2] = true;
    visitados = 1;
    while (q.size() > 0) {
        par cur = q.front(); q.pop();
        int curI = cur.first;
        int curJ = cur.second;
        if (curI - 1 >= 0 && tab[curI-1][curJ] == tab[curI][curJ] && !visit[curI-1][curJ]) {
            visit[curI-1][curJ] = true;
            q.push(par(curI-1, curJ));
            visitados++;
        }
        if (curI + 1 < n && tab[curI+1][curJ] == tab[curI][curJ] && !visit[curI+1][curJ]) {
            visit[curI+1][curJ] = true;
            q.push(par(curI+1, curJ));
            visitados++;
        }
        if (curJ + 1 < m && tab[curI][curJ+1] == tab[curI][curJ] && !visit[curI][curJ+1]) {
            visit[curI][curJ+1] = true;
            q.push(par(curI, curJ+1));
            visitados++;
        }
        if (curJ - 1 >= 0 && tab[curI][curJ-1] == tab[curI][curJ] && !visit[curI][curJ-1]) {
            visit[curI][curJ-1] = true;
            q.push(par(curI, curJ-1));
            visitados++;
        }  
    }  
}

void
correrCol (int col) {
    for (int i = 0; i < n; i++) {
        tab[i][col] = tab[i][col+1];
        tab[i][col+1] = '.';
    }    
}

void
imprimir() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tab[i][j];   
        }   
        puts("");
    }
    puts("\n");
}

int
main() {
    while (cin >> t && t) {
        for (int i = 0; i < n; i++) {
            string line; cin >> line;
            for (int j = 0; j < m; j++) {
                tab[i][j] = line[j];
            }
        }
        //for (int i = 0; i < t; i++) {
        while (t--) {
            char c; cin >> c;
            int posI, posJ; cin >> posI;
            posJ = c - 'a';
            posI = 12 - posI;
            //cout << posI << " " << posJ << endl;
            bfs(posI, posJ);
            if (visitados < 3) continue;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (visit[i][j]) tab[i][j] = '.';   
                }   
            }
            
            //imprimir();
            
            for (int j = 0; j < m; j++) {
                int puntos = 0;
                for (int i = n-1; i >= 0; i--) {
                    if (tab[i][j] == '.') puntos++;
                    else {
                        //D(i-puntos);
                        tab[i+puntos][j] = tab[i][j];
                        if (puntos > 0) tab[i][j] = '.';
                    }
                }
            }
            
            int repito = 0;
            for (int j = 0; j < m - 1 && repito <= m + 5; j++) {
                repito++;
                //D(j);
                if (tab[n-1][j] == '.') {
                    for (int k = j; k < m - 1; k++) {
                        correrCol(k);   
                    }  
                    j--; 
                }   
            }
            
            //imprimir();
        } 
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tab[i][j] != '.') ans++;
            }   
        }
        cout << ans << endl;
    }
    return 0;
}
