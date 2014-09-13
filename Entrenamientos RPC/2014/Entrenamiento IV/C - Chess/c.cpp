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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int t, ci, cf, fi, ff;

int
getCol(char c) {
  return (int) (c - 'A');  
}

int
getFil(int f) {
  return 8 - f; 
}

char
retCol(int c) {
  return (char) (c + 'A'); 
}

int
diagWhite(int sum) {
  return sum/2;
}

int
diagBlack(int sum) {
  return sum/2; 
}

int
main() {
  cin >> t;
  while (t--) {
    vector <char> ansL;
    vector <int> ansL2;
    char colI, colF;
    int filI, filF;
    cin >> colI >> filI >> colF >> filF;
    ci = getCol(colI);
    fi = getFil(filI);
    cf = getCol(colF);
    ff = getFil(filF);
    if ((ci + fi) % 2 != (cf + ff) % 2) {
      puts("Impossible");
      continue;
    }
    
    ansL.push_back(retCol(ci));
    ansL2.push_back(getFil(fi));
    bool hacer = true;
    if (ci == cf && fi == ff) hacer = false;
    int ans = 0;
    if ((ci + fi) % 2 == 0) { //Blanco
      int where = ci + fi;
      if (ci != fi && hacer) {
        where = diagWhite(ci+fi);
        ansL.push_back(retCol(where));
        ansL2.push_back(getFil(where));
        ans++;
        where *= 2;
      }
      if (cf + ff != where && hacer) {
        where = diagWhite(cf + ff);
        ansL.push_back(retCol(where));
        ansL2.push_back(getFil(where));
        ans++;
      }
      if (cf != where && ff != where && hacer) {
        ansL.push_back(retCol(cf));
        ansL2.push_back(getFil(ff));
        ans++;
      }
    }
    else { //negro
      int where = ci + fi;
      if (ci - 1 != fi && hacer) {
        where = diagBlack(ci+fi);
        ansL.push_back(retCol(where + 1));
        ansL2.push_back(getFil(where));
        ans++;
        where = ci + fi;
      }
      if (cf + ff != where && hacer) {
        where = diagBlack(cf + ff);
        ansL.push_back(retCol(where + 1));
        ansL2.push_back(getFil(where));
        ans++;
      }
      if ((cf - 1 != where || ff != where) && hacer) {
        ansL.push_back(retCol(cf));
        ansL2.push_back(getFil(ff));
        ans++;
      }
    }
    cout << ans << " ";
    cout << ansL[0] << " " << ansL2[0];
    for (int i = 1; i < ansL.size(); i++) {
      cout << " " << ansL[i] << " " << ansL2[i];
    }
    puts("");
  }
  return 0;
}
