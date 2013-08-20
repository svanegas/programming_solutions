#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

#define MAX_INT 205

using namespace std;
 
const int MAXN = MAX_INT;
int c, tot, res, d[MAXN];
map <string, int> m;
vector <int> g[MAXN];
string words[MAXN];
string temp, inicio, fin;
float per;

void
limpiar() {
    for(int i = 0; i < tot; i++) {
       //d[i] = -1;
       g[i].clear();
       words[i] = "";
    }
}

void
limpiarDis() {
    for(int i = 0; i < tot; i++) {
        d[i] = -1;
    }
}

void
bfs(int s) {
    queue <int> q;
    q.push(s);
    d[s] = 0;
    while(q.size() > 0) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i];
            if(d[next] == -1) {
                if(words[(next)] == fin) {
                    res = d[cur] + 1;
                    return;   
                }
                d[next] = d[cur] + 1;
                q.push(next);   
            }   
        }    
    }
}

void
hacerGrafo() {
    map <string, int> :: iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        
        int x = it->second;
        string s1 = it->first;
        
        words[(it->second)] = it->first;
        //cout << "Almacené en word[" << x << "] la palabra " << s1 << endl;
        //printf("Almacené en word[%d] la palabra %s\n", x, s1);
        map <string, int> :: iterator it2;
        for(it2 = m.begin(); it2 != m.end(); it2++) {
            string palabra1 = it->first;
            string palabra2 = it2->first;
            
            //cout << "Examinando " << palabra1 << " con " << palabra2 << endl;
            //printf("Examinando %s con %s\n", palabra1, palabra2);
            if(palabra1 != palabra2 && palabra1.size() == palabra2.size()) {
                //puts("Entro");
                int dif = 0;
                for(int k = 0; k < palabra1.size(); k++) {
                    if(palabra1[k] != palabra2[k]) {
                        dif++;   
                    }   
                }
                //printf("Diferencia entre ambas es %d, ", dif);
                if(dif == 1) {
                    //printf("Por lo cual en g[%d] meto a %d\n", i, m[palabra2]);
                    g[it->second].push_back(m[palabra2]);  
                }
            }
        }
    }
}

int
main() {
    cin >> c;
    getline(cin, temp); //Coger el \n del c
    //cout << temp << endl; //Imprimir el \n del c
    getline(cin, temp); //Coger la linea que sigue
    while(c--) {
        tot = 0;
        m.clear();
        while(cin >> temp && temp != "*") {
            m[temp] = tot++;
        }
        getline(cin, temp); //Coger el \n que desps del *
        
        limpiar();
        hacerGrafo();
        
        while(getline(cin, temp) && temp.size() > 0) {
            stringstream ss(temp);
            ss >> inicio;
            //cout << "Inicio: " << inicio << endl;
            ss >> fin;
            //cout << "Fin: " << fin << endl;
            limpiarDis();
            res = 0;
            bfs(m[inicio]);
            cout << inicio << " " << fin << " " << res << endl;
        }
        if(c) {
            cout << endl;
        }
    }
    return 0;
}
