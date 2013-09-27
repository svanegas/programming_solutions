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

const int MAXN = 305;
int m[MAXN][MAXN];
int col[MAXN];
int fila[MAXN];
int dondeFil[MAXN];
int dondeCol[MAXN];
int l, c;

int
main() {
    while (cin >> l >> c) {
        bool posible = true;
        for (int i = 0; i < l; i++) {
            int conj;
            for (int j = 0; j < c; j++) {
                cin >> m[i][j]; m[i][j]--;
                if (j == 0) {
                    conj = m[i][j]/c;
                    fila[i] = conj;
                    dondeFil[conj] = i;
                }
                else if (m[i][j]/c != conj) posible = false;
                if (i == 0) {
                    int val = m[i][j]%c;
                    col[j] = val;
                    dondeCol[val] = j;
                } 
                else if (m[i-1][j]%c != m[i][j]%c) posible = false;
            }
        }
        if (!posible) {
            cout << "*" << endl;
            continue;
        }
        else {
            int ans = 0;
            for (int i = 0; i < l; i++) {
                if (fila[i] != i) {
                    int donde = dondeFil[i];
                    int val = fila[i];
                    swap(fila[i], fila[donde]);
                    dondeFil[i] = i;
                    dondeFil[val] = donde;
                    ans++;
                }
            }   
            for (int j = 0; j < c; j++) {
                if (col[j] != j) {
                    int donde = dondeCol[j];
                    int val = col[j];
                    swap(col[j], col[donde]);
                    dondeCol[j] = j;
                    dondeCol[val] = donde;
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
