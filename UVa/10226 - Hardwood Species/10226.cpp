#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
 
using namespace std;
 
int c, tot;
map <string, int> m;
string temp;
float per;
 
int
main() {
    cin >> c;
    getline(cin, temp); //Coger el \n del c
    //cout << temp << endl; //Imprimir el \n del c
    getline(cin, temp); //Coger la linea que sigue
    while(c--) {
        tot = 0;
        m.clear();
        while(getline(cin, temp) && temp.size() > 0) {
            if(!m[temp]) {
                m[temp] = 1;
            }
            else {
                m[temp]++;
            }
            tot++;
        }
        map <string, int> :: iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            cout << it->first << " ";
            per = ((float)it->second * 100)/(float)tot;
            printf("%.4lf\n", per);
        }
        if(c) {
            cout << endl;
        }
    }
    return 0;
}
