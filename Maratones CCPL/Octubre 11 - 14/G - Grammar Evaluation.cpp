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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl;

int isExp(const string &s);

int
isFact(const string &s) {
    if (s.size() == 0) return -1;
    if (s[0] == '(' && s[s.size() - 1] == ')') {
        return isExp(s.substr(1, s.size() - 2));
    }
    else {
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) return -1;       
        }
        int ans = toInt(s);
        if (ans <= 0) return -1;
        else return ans;
    }
}

int
isComp(const string &s) {
    if (s.size() == 0) return -1;
    stack <char> q;
    int ans = 1;
    int i = 0;
    string expr = "";
    while (i < s.size()) {
        if (s[i] == '(') q.push(s[i]);
        else if (s[i] == ')') {
            if (q.empty()) return -1;
            else q.pop();   
        }
        else if (s[i] == '*') {
            if (q.empty()) {
                int fact = isFact(expr);
                if (fact == -1) return -1;
                else ans *= fact;
                if (i == s.size() - 1) return -1;
                else {
                    int right = isComp(s.substr(i+1, s.size()));
                    if (right == -1) return -1;
                    else return ans *= right;   
                }
            }
        }
        expr += s[i];
        ++i;
    }
    if (expr.size() > 0) return isFact(expr);
}

int
isExp(const string &s) {
    if (s.size() == 0) return -1;
    stack <char> q;
    int ans = 0;
    int i = 0;
    string expr = "";
    while (i < s.size()) {
        if (s[i] == '(') q.push(s[i]);
        else if (s[i] == ')') {
            if (q.empty()) return -1;
            else q.pop();   
        }
        else if (s[i] == '+') {
            if (q.empty()) {
                int comp = isComp(expr);
                if (comp == -1) return -1;
                else ans += comp;
                if (i == s.size() - 1) return -1;
                else {
                    int right = isExp(s.substr(i+1, s.size()));
                    if (right == -1) return -1;
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
        int ans = isExp(s);
        if (ans == -1) cout << "ERROR" << endl;
        else cout << ans << endl;   
    }
    return 0;
}
