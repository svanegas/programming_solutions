#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>

using namespace std;

template <class T> int toInt(const T &x) {
  stringstream s; s << x; int r; s >> r; return r;
}

bool
poss(string num, bitset <65> foo, vector <int> bar, int maxi) {
  if (num.size() == 0) {
    for (int i = 1; i <= maxi; ++i) {
      if (!foo[i]) return false;
    }
    cout << bar[0];
    for (int i = 1; i < bar.size(); ++i) {
      cout << " " << bar[i];
    }
    cout << endl;
    return true;
  }
  if (num.size() == 1) {
    int val = toInt(num);
    if (foo[val]) return false;
    foo[val] = true;
    bar.push_back(val);
    return poss("", foo, bar, max(maxi, val));
  }
  // 1. Try only the first digit
  bool modi = false;
  int val = toInt(num[0]);
  if (!foo[val]) {
    modi = true;
    foo[val] = true;
    bar.push_back(val);
    if (poss(num.substr(1, num.size()), foo, bar, max(maxi, val))) return true;
  }
  if (num[0] <= '5') {
    // 2. Try joining the first and second digit.
    if (modi) {
      foo[val] = false;
      bar.pop_back();
    }  
    val = toInt(num.substr(0, 2));
    if (foo[val]) return false;
    foo[val] = true;
    bar.push_back(val);
    string nextString = num.size() == 2 ? "" : num.substr(2, num.size());
    if (poss(nextString, foo, bar, max(maxi, val))) return true;
  }
  return false;
}

int
main() {
  string s;
  while (cin >> s) {
    bitset <65> foo;
    vector <int> bar;
    poss(s, foo, bar, 0);
  }
  return 0;
}
