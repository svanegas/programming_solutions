using namespace std;
#include <iostream>
#include <algorithm>
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
#include <stack>
#include <list>
#include <map>
#include <set>

//team550
//53763843

#define D(x) //cout << #x " = " << (x) << endl

template <class T> string toStr(const T &x) {
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x) {
stringstream s; s << x; int r; s >> r; return r;
}

vector <int> equis;
vector <int> nums;

string
solveEquations(string s){
    string first = "";
    int termina = 0;
    for (int i = 0; s[i] != '='; i++) {
        first += s[i];
        termina = i;
    }
    termina += 2;
    if (first[0] != '-') first.insert(first.begin(), '+');

    int i = 0;
    while (i < first.size()) {
        int sign = (first[i] == '+') ? 1 : -1;
        string num = "";
        i++;
        for (i; i < first.size() && first[i] != '+' && first[i] != '-'; i++) num += first[i];
        D(num);
        if (num[num.size() - 1] == 'x') {
            num.erase(num.size() - 1);
            if (num.size() == 0) equis.push_back(1 * sign);
            else equis.push_back(toInt(num) * sign);
        }
        else nums.push_back(toInt(num) * sign * -1);
    }

    string last = "";
    for (int i = termina; i < s.size() ; i++) last += s[i];
    if (last[0] != '-') last.insert(last.begin(), '+');

    D(last);
    i = 0;
    while (i < last.size()) {
        int sign = (last[i] == '+') ? -1 : 1;
        string num = "";
        i++;
        for (i; i < last.size() && last[i] != '+' && last[i] != '-'; i++) num += last[i];
        D(num);
        if (num[num.size() - 1] == 'x') {
            num.erase(num.size() - 1);
            if (num.size() == 0) equis.push_back(1 * sign);
            else equis.push_back(toInt(num) * sign);
        }
        else nums.push_back(toInt(num) * sign * -1);
    }

    int nAns = 0;
    for (int i = 0; i < nums.size(); i++) {
        //cout << nums[i] << endl;
        nAns += nums[i];
    }

    int xAns = 0;
    for (int i = 0; i < equis.size(); i++) {
        //cout << equis[i] << endl;
        xAns += equis[i];
    }

    D(xAns); D(nAns);
    if (xAns == 0 && nAns == 0) return "IDENTITY";
    if (xAns == 0 && nAns != 0) return "IMPOSSIBLE";
    if (xAns != 0 && nAns != 0) return toStr(floor((nAns * 1.0/xAns * 1.0)));
    if (xAns != 0 && nAns == 0) return "0";
    return "0";
}


int main(){
    int n; cin >> n;
    string equation;
    getline(cin,equation);
    for(int i=0; i<n;i++){
        nums.clear();
        equis.clear();
        string equation;
        getline(cin,equation);
        cout << solveEquations(equation) << endl;
    }
    return 0;
}
