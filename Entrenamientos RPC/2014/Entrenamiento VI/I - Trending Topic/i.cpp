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

const int MAXD = 1005;
map <string, int> mDay[MAXD];
int n, actDay = 1;

struct Occ {
  string word;
  int times;
  Occ (string Word, int Times) : word(Word), times(Times) { }
  
  bool operator <(const Occ &other) const {
    if (times < other.times) return false;
    else if (times > other.times) return true;
    else return word < other.word;
  }
};

void
printfreq() {
  vector <Occ> words;
  map <string, int> m;
  int from = max(1, actDay - 7);
  map <string, int> :: iterator it;
  for (int i = from; i < actDay; i++) {
    for (it = mDay[i].begin(); it != mDay[i].end(); it++) {
      m[it->first] += it->second; 
    } 
  }
  for (it = m.begin(); it != m.end(); it++) {
    words.push_back(Occ(it->first, it->second));
  }
  sort(words.begin(), words.end());
  int cont = 0;
  cout << "<top " << n << ">" << endl;
  for (int i = 0; i < words.size() && cont < n; i++) {
    if (cont == n) break;
    else {
      int index = i;
      int tim = words[index].times;
      while (index < words.size() && words[index].times == tim) {
        cout << words[index++].word << " " << tim << endl;
        cont++; 
      }
      i = index - 1;
    } 
  }
  cout << "</top>" << endl;
}

int
main() {
  string s;
  actDay = 1;
  while (cin >> s) {
    if (s == "<text>") continue;
    if (s == "</text>") {
      actDay++;
      continue; 
    }
    if (s == "<top") {
      cin >> n;
      cin >> s;
      printfreq();
      continue;
    }
    if (s.size() < 4) continue;
    mDay[actDay][s]++;
  }
  return 0;
}
