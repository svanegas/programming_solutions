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

stack <string> cola;
string linea, palabra, res;
int c, n, z;

int
main() {
    z = 1;
    cin >> c;
    getchar();
    while (c--) {
        printf("Case #%d: ", z++);
        stack <string> cola;
        getline(cin, linea);
        stringstream ss(linea);
        while (ss >> palabra) {
            cola.push(palabra);   
        }
        res = cola.top(); cola.pop();
        n = cola.size();
        for(int i = 0; i < n; i++) {
            res = res + " " + cola.top();
            cola.pop();
        }
        cout << res << endl;
    }
    return 0;
}
