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

int casos, cont, z;
long long r, t, auxR, auxT;

int
pintar(int radio) {
    return ((radio*radio) - ((radio-1)*(radio-1)));
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
        //cout << "Leí como r: " << r << " y como t: " << t << endl;
        while (pinto) {
            int costo = pintar(auxR+1);
            //printf("El costo de pintar %d es %d\n", auxR+1, costo);
            if (auxT - costo >= 0) {
                auxT -= costo;
                cont++;
                auxR = auxR + 2;
                //printf("Como tengo %d mls y la resta da %d puedo pintar\n", auxT, auxT-costo);
            }
            else {
                pinto = false;
                //printf("No pinto porque tengo %d mls y la resta da %d\n", auxT, auxT-costo);
            }
        }
        cout << cont << endl;
    }
    return 0;
}
