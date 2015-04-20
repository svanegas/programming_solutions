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

const int MAXN = 30;
set <char> letras [MAXN];
vector <string> palabras;
string linea;
int l, d, n, z, cont;
bool esta;

int
main() {
    z = 1;
    cin >> l >> d >> n;
    for(int i = 0; i < d; i++) {
        string p;
        cin >> p;
        palabras.push_back(p);
    }
    getchar();
    while(n--) {
        for(int i = 0; i < l; i++) {
            letras[i].clear();   
        }
        printf("Case #%d: ", z++);
        getline(cin, linea);
        int aux = 0;
        for(int i = 0; i < linea.size(); i++) {
            if(linea[i] == '(') {
                int j = i+1;
                while(linea[j] != ')') {
                    letras[aux].insert(linea[j]);
                    j++;
                }
                i = j;
                aux++;
                continue;
            }
            letras[aux].insert(linea[i]);
            aux++;
        }
        
        cont = 0;
        for(int i = 0; i < palabras.size(); i++) {
            esta = true;
            string tmp = palabras[i];
            for(int j = 0; j < l; j++) {
                if(letras[j].count(tmp[j]) == 0) esta = false;  
            }
            if(esta) cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
