//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n, z = 1;
string alph;
map <char, char> mToOrig, origToM;
vector <string> words;

int
main() {
  while (cin >> n && n) {
    words.clear();
    mToOrig.clear();
    origToM.clear();
    cin >> alph;
    for (char c = 'A', i = 0; c <= 'Z'; i++, c++) {
      mToOrig[alph[i]] = c;
      origToM[c] = alph[i];
    }
    for (int i = 0; i < n; i++) {
      string word; cin >> word; 
      for (int j = 0; j < word.size(); j++) word[j] = mToOrig[word[j]];
      words.push_back(word);
    }
    sort(words.begin(), words.end());
    printf("year %d\n", z++);
    for (int i = 0; i < n; i++) {
      string word = words[i];
      for (int j = 0; j < word.size(); j++) {
        cout << origToM[word[j]];
      }
      puts(""); 
    }
  }
  return 0;
}
