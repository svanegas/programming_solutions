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

const int MAXN = 25;
int pos[MAXN];
int cant, n;
map <int, int> m;
bool modificado;

void
ordenar() {
    while (true) {
        modificado = false;
        for(int i = 1; i < n; i++){
            if(pos[i] < pos[i-1]) {
                swap(pos[i], pos[i-1]);
                modificado = true;
                cant++;
            }
        }
        if(!modificado) break;
    }
}

int
main() {
    while (cin >> n) {
        m.clear();
        cant = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x] = i+1; 
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pos[i] = m[x];   
        }
        ordenar();
        cout << cant << endl;
    }
    return 0;
}
