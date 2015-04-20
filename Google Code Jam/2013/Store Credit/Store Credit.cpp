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

int r, t, auxR, auxT, cont;

int
pintar(int radio) {
    return (radio^2 - (radio-1)^2);    
}

int
main() {
    cin >> casos;
    z = 1;
    while (casos--) {
        printf("Case #%d: ", z++);
        bool pinto = true;
        cin >> r >> t;
        auxR = r; auxT = t; cont = 0;
        while (pinto) {
            int costo = pintar(t+1);
            if (auxT - costo >= 0) {
                auxT -= costo;
                cont++;
            }
            else pinto = false;
        }
        cout << cont << endl;
    }
    return 0;
}
