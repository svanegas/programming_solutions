//Santiago Vanegas Gil.
#include <iostream>

using namespace std;

long long n, m, a;

int
main() {
  cin >> n >> m >> a;
  cout << ((n / a) + (n % a != 0LL)) * ((m / a) + (m % a != 0LL)) << endl;
  return 0;
}
