#include <bits/stdc++.h>

using namespace std;

string s;
map <char, int> m;

struct data {
    char l;
    int t;
    data(char L, int T) : l(L), t(T) {}

    bool operator <(const data &other) const {
      if (t < other.t) return true;
      else if (t == other.t) {
        if (l > other.l) return true;
        return false;
      }
      else {
        return false;
      }
    }
};

int main() {
  char c;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    m[s[i]]++;
  }
  vector <data> v;
  map<char, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it) {
    v.push_back(data(it->first, it->second));
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].t; ++j) {
      cout << v[i].l;
    }
  }
  cout << endl;
  return 0;
}
