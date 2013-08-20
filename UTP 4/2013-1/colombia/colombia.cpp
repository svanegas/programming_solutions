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

const int MAXN = 1000005;
vector<double> lista;

void bubbleSort(int n) {
    bool cambiado = true;
    int j = 0;
    double tmp;
    while (cambiado) {
        cambiado = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (lista[i] > lista[i + 1]) {
                tmp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = tmp;
                cambiado = true;
            }
        }
    }
}

int
mediana(int n){
    if (n%2 == 1) {
        int r = n/2;
        //printf("%.1lf\n", nume[r]);
        //cout << "mediana: " << lista[r] << endl;
        return (int)lista[r];
    }
    else {
        int r = (n/2) - 1;
        int res = (int)(lista[r] + lista[r+1]) / 2;
        //printf("%.1lf\n", res);
        //cout << "mediana: " << res << endl;
        return (int)res;
    }
}

int
main() {
    int n;
    while (cin >> n && n != 0) {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            double x; cin >> x;
            lista.push_back(x);
            //cout << "leo: " << x << " size: " << lista.size() << endl;
            //sort(lista.begin(), lista.begin()+(i+1));
            bubbleSort(i+1);
            tot += mediana(i+1);
        }
        //cout << "tot: " << tot << endl;
        double rpta = (double)tot/(double)n;
        printf("%.2lf\n", rpta);
    }
    return 0;
}
