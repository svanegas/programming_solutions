#include <iostream>
#include <cmath>

using namespace std;

long long a, b, c;

int
main() {
    while(cin >> a >> b) {
        c = abs(a-b);
        cout << c << endl;
    }
    return 0;
}
