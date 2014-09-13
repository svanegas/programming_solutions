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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n, k, p;
vector <int> pares;
vector <int> impares;

vector <vector <int> > aPares;
vector <vector <int> > aImpares;

int
main() {
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    (xi % 2 ? impares : pares).push_back(xi);
  }
  k -= p;
  if (k > impares.size() ||
      (impares.size() - k) % 2 != 0  ||
      pares.size() + ((impares.size() - k) / 2) < p) {
    puts("NO");
    return 0;      
  }
  else {
    while (k && !impares.empty()) {
      vector <int> tmp;
      tmp.push_back(impares.back());
      impares.pop_back();
      aImpares.push_back(tmp);
      k--;   
    }
    while (p && !pares.empty()) {
      vector <int> tmp;
      tmp.push_back(pares.back());
      pares.pop_back();
      aPares.push_back(tmp);
      p--;
    }
    while (p && !impares.empty()) {
      vector <int> tmp;
      tmp.push_back(impares.back());
      impares.pop_back();
      tmp.push_back(impares.back());
      impares.pop_back();
      aPares.push_back(tmp);
      p--;
    }
    while ((aPares.size() > 0 || p) && !impares.empty()) {
      if (aPares.size() == 0) {
        vector <int> temp;
        aPares.push_back(temp);
        p--;  
      }
      aPares[0].push_back(impares.back());
      impares.pop_back();
      aPares[0].push_back(impares.back());
      impares.pop_back();
    }
    while (aImpares.size() > 0 && !impares.empty()) {
      aImpares[0].push_back(impares.back());
      impares.pop_back();
      aImpares[0].push_back(impares.back());
      impares.pop_back();
    }
    while (aPares.size() > 0 && !pares.empty()) {
      aPares[0].push_back(pares.back());
      pares.pop_back();
    }
    while (aImpares.size() > 0 && !pares.empty()) {
      aImpares[0].push_back(pares.back());
      pares.pop_back();
    }
    puts("YES");
    for (int i = 0; i < aPares.size(); i++) {
      cout << aPares[i].size();
      for (int j = 0; j < aPares[i].size(); j++) {
        cout << " " << aPares[i][j]; 
      } 
      puts("");
    }
    for (int i = 0; i < aImpares.size(); i++) {
      cout << aImpares[i].size();
      for (int j = 0; j < aImpares[i].size(); j++) {
        cout << " " << aImpares[i][j]; 
      } 
      puts("");
    }
  }
  return 0;
}
