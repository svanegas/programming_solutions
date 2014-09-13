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

typedef pair <int, int> par;
const int n = 12;
const int m = 10;
int t;
char tab[n][m];
bool visit[n][m];

bool
bfs(int sI, int sJ) {
    if (tab[sI][sJ] == '.') return false;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visit[i][j] = false;
    queue <par> q;
    q.push(par(sI, sJ));
    visit[sI][sJ] = true;
    int explode = 1;
    while (!q.empty()) {
        par cur = q.front(); q.pop();
        int curI, curJ;
        curI = cur.first;
        curJ = cur.second;
        if (curI - 1 >= 0 && !visit[curI - 1][curJ] && tab[curI - 1][curJ] == tab[sI][sJ]) {
            visit[curI - 1][curJ] = true;
            tab[curI - 1][curJ] = '.';
            q.push(par(curI - 1, curJ));
            explode++;
        }
        if (curI + 1 < n  && !visit[curI + 1][curJ] && tab[curI + 1][curJ] == tab[sI][sJ]) {
            visit[curI + 1][curJ] = true;
            tab[curI + 1][curJ] = '.';
            q.push(par(curI + 1, curJ));
            explode++;
        }
        if (curJ - 1 >= 0 && !visit[curI][curJ - 1] && tab[curI][curJ - 1] == tab[sI][sJ]) {
            visit[curI][curJ - 1] = true;
            tab[curI][curJ - 1] = '.';
            q.push(par(curI, curJ - 1));
            explode++;
        }
        if (curJ + 1 < m && !visit[curI][curJ + 1] && tab[curI][curJ + 1] == tab[sI][sJ]) {
            visit[curI][curJ + 1] = true;
            tab[curI][curJ + 1] = '.';
            q.push(par(curI, curJ + 1));
            explode++;
        }
    }
    if (explode < 3) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (visit[i][j]) tab[i][j] = tab[sI][sJ];     
        return false;
    }
    else {
        tab[sI][sJ] = '.';
        return true;
    }
}

void
bajarFichas() {
    for (int j = 0; j < m; j++) {
        int puntos = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (tab[i][j] == '.') puntos++;
            else {
                tab[i+puntos][j] = tab[i][j];
                if (puntos > 0) tab[i][j] = '.';   
            }
        }   
    }   
}

void
correrColumna(int j) {
    for (int i = 0; i < n; i++) {
        tab[i][j-1] = tab[i][j];
        tab[i][j] = '.';   
    }
}

void
correrFichas() {
    int corridas = 0;
    for (int j = 0; j < m && corridas <= m; j++) {
        if (tab[n-1][j] == '.') {
            for (int k = j + 1; k < m; k++) {
                correrColumna(k);
            }
            j--;
            corridas++;
        }   
    }    
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
        while (t--) {
            char lCol;
            int col, fil;
            cin >> lCol >> fil;
            col = (int) (lCol - 'a');
            fil = 12 - fil;
            if (bfs(fil, col)) {
                bajarFichas();
                correrFichas();
            }
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tab[i][j] != '.') tot++;
            }   
        }
        cout << tot << endl;
    }
	return 0;
}
