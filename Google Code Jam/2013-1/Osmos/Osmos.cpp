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

priority_queue < int, vector <int>,
                    greater<int> > q;
int cont, a, n;
                
void
chupar(int a) {
    while (!q.empty()) {
        int v = q.top();
        if (v < a) {
            a += v;
            q.pop();
            cont--;
        }
        else return;
    }
}

int
main() {
    int c; cin >> c;
    int z = 1;
    while (c--) {
        cont = 0;
        q = priority_queue < int, vector <int>,
                    greater<int> >();
        printf("Case #%d: ", z++);
        cin >> a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            if (t < a) a += t;
            else {
                q.push(t);
                cont++;
                printf("Meto a %d size %d\n", t, q.size());
            }
        }
        chupar(a);
        printf("Size %d\n", q.size());
        if (cont == 0) {
            cout << cont << endl;
            continue;   
        }
        if (a == 1) {
            cout << q.size() << endl;
            continue;
        }
        int tempA = a;
        int tCont = 0;
        printf("Entro con tempA = %d y size %d\n", tempA, q.size());
        do {
            tempA += (tempA - 1);
            chupar(tempA);
            tCont++;
            printf("Chupo y quedo en size %d y cont %d\n", q.size(), tCont);
        } while (!q.empty() && tCont < cont);
        
        if (tCont == cont) {
            cout << q.size() << endl;
            continue;   
        }
        else {
            cout << tCont << endl;
            continue;   
        }
    }
    return 0;
}
