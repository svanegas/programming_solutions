#include <iostream>

using namespace std;

int n, previous, cur;

int
main() {
  cin >> n;
  cin >> previous;
  while (--n) {
    cin >> cur;
    if (cur < previous) {
      cout << "Desordenado" << endl;
      return 0;
    }
    previous = cur;
  }
  cout << "Ordenado" << endl;
  return 0;
}
