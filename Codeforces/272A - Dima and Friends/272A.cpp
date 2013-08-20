#include <iostream>

using namespace std;

int
main() {
    int n, t = 0, c = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        t += aux;   
    }
    for(int i = 1; i < 6; i++) {
        if(((t-1)+i)%(n+1) != 0) {
            c++;   
        }
    }
    
    cout << c;
    return 0;   
}
