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

#define D(x) //cout << #x " = " << (x) << endl;

using namespace std;

typedef vector <string> p;
typedef pair <int, p> estr;
vector <string> palabras;
map <string, bool> m;
priority_queue <estr> q;
map <string, p> mRes;
string linea;

int
main() {
    while(cin >> linea) palabras.push_back(linea);
    sort(palabras.begin(), palabras.end());
    for(int i = 0; i < palabras.size(); i++) {
        string pal = palabras[i];
        D(pal);
        vector <char> pOrd;
        for(int k = 0; k < pal.size(); k++) pOrd.push_back(pal[k]);
        sort(pOrd.begin(), pOrd.end());
        if (m[pal] == false) {
            m[pal] = true;
            p vPal = mRes[pal];
            vPal.push_back(pal);
            mRes[pal] = vPal;
            for(int j = 0; j < palabras.size(); j++) {
                string pal2 = palabras[j];
                if (pal2.size() != pal.size()) {
                    continue;
                }
                if (m[pal2] == false) {
                    vector <char> pOrd2;
                    for(int k = 0; k < pal2.size(); k++) {
                        pOrd2.push_back(pal2[k]);
                    }
                    sort(pOrd2.begin(), pOrd2.end());
                    bool grupo = true;
                    
                    /*cout << "Size: " << pOrd.size() << endl;
                    priority_queue <char> temp1;
                    priority_queue <char> temp2;
                    temp1 = pOrd; temp2 = pOrd2;
                    for(int k = 0; k < pal.size(); k++) {
                        cout << temp1.top() << " = " << temp2.top() << endl;
                        temp1.pop(); temp2.pop();
                    }*/
                    
                    for(int k = 0; k < pal.size(); k++) {
                        if (pOrd[k] != pOrd2[k]) {
                            grupo = false;
                            break;  
                        }
                        /*
                        if (pOrd.top() == pOrd2.top()) {
                            cout << "Afir" << endl;
                            pOrd.pop(); pOrd2.pop();  
                        }
                        else {
                            cout << "Negue" << endl;
                            grupo = false;
                            break;   
                        }*/
                    }
                    if (grupo == true) {
                        m[pal2] = true;
                        p tmp = mRes[pal];
                        tmp.push_back(pal2);
                        mRes[pal] = tmp;
                    }
                }   
            }
            p tmp = mRes[pal];
            int s = tmp.size();
            q.push(estr(s, tmp));
        }
    }
    int n = 5;
    estr r;
    while ( (!q.empty()) && (n--)) {
        r = q.top(); q.pop();
        printf("Group of size %d:", r.first);
        for(int i = 0; i < r.second.size(); i++) {
            cout << " " << r.second[i]; 
        }
        puts("");
    }
    return 0;
}
