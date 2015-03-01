using namespace std;
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

typedef long long ll;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> ll toInt(const T &x)
{ stringstream s; s << x; ll r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl;

ll isExp(const string &s);

ll
isFact(const string &s) {
    if (s.size() == 0LL) {
      //puts("Error is fac vacio");
      return -1LL;
    }
    if (s[0] == '(' && s[s.size() - 1] == ')') {
        return isExp(s.substr(1, s.size() - 2));
    }
    else {
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) {
              //puts("Error is fac no es digito");
              return -1LL;       
            }
        }
        ll ans = toInt(s);
        if (ans < 0LL) {
          //puts("Error is fac dio negativo");
          //printf("El string era: %s\n", s.c_str());
          return -1LL;
        }
        else return ans;
    }
}

ll
isComp(const string &s) {
    if (s.size() == 0) {
      //puts("Error is comp vacío");
      return -1LL;
    }
    stack <char> q;
    ll ans = 1LL;
    int i = 0;
    string expr = "";
    while (i < s.size()) {
        if (s[i] == '(') q.push(s[i]);
        else if (s[i] == ')') {
            if (q.empty()) {
              //puts("Error isComp cerrando paréntesis que no existe");
              return -1LL;
            }
            else q.pop();   
        }
        else if (s[i] == '*') {
            if (q.empty()) {
                ll fact = isFact(expr);
                if (fact == -1) {
                  //puts("Error isComp cuando encuentro un *, la izq no es fact");
                  return -1LL;
                }
                else ans *= fact;
                if (i == s.size() - 1) {
                  //puts("Error isComp error hay un * al final");
                  return -1LL;
                }
                else {
                    ll right = isComp(s.substr(i+1, s.size()));
                    if (right == -1LL) {
                      //puts("Error isComp, despues de un *, la derecha no es otro comp");
                      return -1LL;
                    }
                    else return ans *= right;   
                }
            }
        }
        expr += s[i];
        ++i;
    }
    if (expr.size() > 0) return isFact(expr);
}

ll
isExp(const string &s) {
    if (s.size() == 0) {
      //puts("Error isExp vacio");
      return -1LL;
    }
    stack <char> q;
    ll ans = 0LL;
    int i = 0;
    string expr = "";
    while (i < s.size()) {
        if (s[i] == '(') q.push(s[i]);
        else if (s[i] == ')') {
            if (q.empty()) {
              //puts("Error isExp cerrando algo q no existe");
              return -1LL;
            }
            else q.pop();   
        }
        else if (s[i] == '+') {
            if (q.empty()) {
                ll comp = isComp(expr);
                if (comp == -1) {
                  //puts("Error isExp cuando encuentro mas, la izq no es comp");
                  return -1LL;
                }
                else ans += comp;
                if (i == s.size() - 1) {
                  //printf("Error isExp, había un + al final");
                  return -1LL;
                }
                else {
                    ll right = isExp(s.substr(i+1, s.size()));
                    if (right == -1LL) {
                      //puts("Error isExp, encuentro + pero la derecha no es coso");
                      return -1LL;
                    }
                    else return ans += right;   
                }
            }
        }
        expr += s[i];
        ++i;
    }
    if (expr.size() > 0) return isComp(expr);
}

int n;

int main(){
    cin >> n;
    string tash;
    getline(cin, tash);
    while (n--) {
        string s;
        getline(cin, s);
        ll ans = isExp(s);
        if (ans == -1LL) cout << "ERROR" << endl;
        else cout << ans << endl;   
    }
    return 0;
}
