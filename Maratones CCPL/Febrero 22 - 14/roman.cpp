#include <iostream>
#include <algorithm>
#include <iterator>
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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) //cout << #x " = " << (x) << endl

using namespace std;

string unidades[12];
string decenas[12];
string centenas[12];
string miles[5];

map <char, int> m;

template <class T> int toInt(const T&x) {
    stringstream s; s << x; int r; s >> r; return r;
}

string numToRoma(int x) {
    string res = "";
    int uni = x%10;
    int dec = ((x/10) % 10);
    int cent = ((x/100) % 10);
    int mile = ((x/1000) % 10);
    if (mile != 0) res += miles[mile];
    if (cent != 0) res += centenas[cent];
    if (dec != 0) res += decenas[dec];
    if (uni != 0) res += unidades[uni];
    return res;
}

int romaToNum(string s) {
    int sum = 0;
    bool sumarUltimo = false;
    for (int i = 0; i < s.size() - 1; i++) {
        if (m[s[i]] >= m[s[i+1]]) {
            sum += m[s[i]];
        }
        else {
            if (i == s.size() - 2) sumarUltimo = true;
            sum += (m[s[i+1]] - m[s[i]]);
            i++;
        }
    }
    if (!sumarUltimo) sum += m[s[s.size()-1]];
    return sum;
}

int
main() {
    unidades[1] = "I";
    unidades[2] = "II";
    unidades[3] = "III";
    unidades[4] = "IV";
    unidades[5] = "V";
    unidades[6] = "VI";
    unidades[7] = "VII";
    unidades[8] = "VIII";
    unidades[9] = "IX";
    unidades[10] = "X";
    decenas[1] = "X";
    decenas[2] = "XX";
    decenas[3] = "XXX";
    decenas[4] = "XL";
    decenas[5] = "L";
    decenas[6] = "LX";
    decenas[7] = "LXX";
    decenas[8] = "LXXX";
    decenas[9] = "XC";
    decenas[10] = "C";
    centenas[1] = "C";
    centenas[2] = "CC";
    centenas[3] = "CCC";
    centenas[4] = "CD";
    centenas[5] = "D";
    centenas[6] = "DC";
    centenas[7] = "DCC";
    centenas[8] = "DCCC";
    centenas[9] = "CM";
    centenas[10] = "M";
    miles[1] = "M";
    miles[2] = "MM";
    miles[3] = "MMM";
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    string s;
    while (cin >> s) {
        if (isdigit(s[0])) cout << numToRoma(toInt(s)) << endl;
        else cout << romaToNum(s) << endl;
    }
    return 0;
}
