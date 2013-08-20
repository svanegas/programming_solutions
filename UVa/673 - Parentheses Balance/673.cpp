#include <iostream>
#include <string>
#include <map>

using namespace std;

int p, c, casos;
string linea;
map <char, int> m;
bool force, inicio;

int
main() {
    m['['] = 1;
    m[']'] = -1;
    m['('] = 1;
    m[')'] = -1;
    cin >> casos;
    inicio = true;
    while(casos > 0) {
        getline(cin, linea);
        if(inicio) {
            getline(cin, linea);
            inicio = false;   
        }
        if(linea.size() == 0) cout << "Yes" << endl;
        else {
            p = 0, c = 0, force = false;
            for(int i = 0; i < linea.size() && p >= 0 && c >= 0; i++) {
                char car = linea[i];
                if(car == ')' && !(p > 0)) {
                    cout << "No" << endl;
                    force = true;
                    break;
                }   
                if(car == ')' && i-1 >= 0 && linea[i-1] == '[') {
                    cout << "No" << endl;
                    force = true;
                    break;
                }
                if(car == ']' && !(c > 0)) {
                    cout << "No" << endl;
                    force = true;
                    break;
                }
                if(car == ']' && i-1 >= 0 && linea[i-1] == '(') {
                    cout << "No" << endl;
                    force = true;
                    break;
                }
                if(car == ']' || car == '[') {
                    c += m[car];   
                }
                else {
                    p += m[car];   
                }
            }
            if(p == 0 && c == 0 && !force) cout << "Yes" << endl;
            else if (!force)
                cout << "No" << endl;
        }
        casos--;
    }
    return 0;
}
