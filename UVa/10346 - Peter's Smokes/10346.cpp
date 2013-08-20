#include <iostream>

using namespace std;

int n, k, res;

int
main() {
    while(cin >> n >> k) {
        res = n;
        while(k <= n) {
            res += n / k;
            n = n / k + n % k;
        }
        cout << res << endl;
    }
    return 0;
}
