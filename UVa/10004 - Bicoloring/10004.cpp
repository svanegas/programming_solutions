#include <iostream>
#include <vector>

using namespace std;

int n, l, a, b;
vector <int> g[200];
int color[200];

void
clean() {
    for(int i = 0; i < n; i++) {
        color[i] = -1;
        g[i].clear();
    }   
}

bool
fcolor(int nodo, int pin) {
    color[nodo] = pin;
    for(int i = 0; i < g[nodo].size(); i++) {
        int nodo2 = g[nodo].at(i);
        bool pintar;
        if(color[nodo2] == -1) {
            pintar = fcolor(nodo2, 1 - pin);
        }
        else {
            if(color[nodo2] == color[nodo]) {
                pintar = false;   
            }
            else {
                pintar = true;
            }
        }
        if(!pintar) return false;
    }
    return true;
}

int
main() {
    while(cin >> n && n != 0) {
        cin >> l;
        clean();
        for(int i = 0; i < l; i++) {
            cin >> a >> b;
            g[a].push_back(b);
            if(a != b) {
                g[b].push_back(a);
            }
        }
        if(fcolor(1, 1)) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0; 
}
