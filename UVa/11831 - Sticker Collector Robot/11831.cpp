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

const int MAXN = 105;
int n, m, x, y, looking, dulces, movs;
char arena[MAXN][MAXN];

void
rotar(char c) {
    if (c == 'D' and looking == 3) {
        looking = 0;
        return;   
    }   
    if (c == 'E' and looking == 0) {
        looking = 3;
        return;   
    }
    looking += (c == 'D') ? 1 : -1;
}

void
mover() {
    int newX, newY;
    switch (looking) {
        case 0:
            newX = x - 1;
            newY = y;
            break;
        case 1:
            newX = x;
            newY = y + 1;
            break;
        case 2:
            newX = x + 1;
            newY = y;
            break;
        case 3:
            newX = x;
            newY = y - 1;
            break;        
    }
    if (newX >= 0 && newY >= 0 && newX < n && newY < m &&
        arena[newX][newY] != '#') {
            x = newX;
            y = newY;
            if (arena[newX][newY] == '*') {
                dulces++;
                arena[newX][newY] = '.';   
            }        
            
    }
}

int
main() {
    while (cin >> n >> m >> movs && n && m && movs) {
        dulces = 0;
        for (int i = 0; i < n; i++) {
            string row; cin >> row;
            for (int j = 0; j < m; j++) {
                arena[i][j] = row[j];
                if (row[j] == 'N') {
                    looking = 0;
                    x = i;
                    y = j;
                    arena[i][j] = '.';
                }
                if (row[j] == 'L') {
                    looking = 1;
                    x = i;
                    y = j;
                    arena[i][j] = '.';
                }
                if (row[j] == 'S') {
                    looking = 2;
                    x = i;
                    y = j;
                    arena[i][j] = '.';
                }
                if (row[j] == 'O') {
                    looking = 3;
                    x = i;
                    y = j;
                    arena[i][j] = '.';
                }
            }   
        }
        string acciones; cin >> acciones;
        for (int i = 0; i < movs; i++) {
            if (acciones[i] == 'F') {
                mover();
            }   
            else {
                rotar(acciones[i]);
            }
        }
        cout << dulces << endl;
    }
	return 0;
}
