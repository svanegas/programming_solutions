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

#define D(x) cout << #x " = " << (x) << endl

template <class T> string toStr(const T &x) {
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x) {
stringstream s; s << x; int r; s >> r; return r;
}

int t, k;
map <string, int> monthToNum;
int iniDay, iniMonth, iniYear;

int nDays [][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void
leerFecha() {
    string s;
    cin >> s;
    string tmpYear, tmpMes, tmpDay;
    tmpYear = tmpMes = tmpDay = "";
    int i;
    for (i = 0; s[i] != '-'; i++) tmpYear += s[i];
    i++;
    for (i; s[i] != '-'; i++) tmpMes += s[i];
    i++;
    for (i; i < s.size(); i++) tmpDay += s[i];
    iniYear = toInt(tmpYear);
    iniMonth = monthToNum[tmpMes];
    iniDay = toInt(tmpDay);
}

int main() {
    monthToNum["January"] = 0;
    monthToNum["February"] = 1;
    monthToNum["March"] = 2;
    monthToNum["April"] = 3;
    monthToNum["May"] = 4;
    monthToNum["June"] = 5;
    monthToNum["July"] = 6;
    monthToNum["August"] = 7;
    monthToNum["September"] = 8;
    monthToNum["October"] = 9;
    monthToNum["November"] = 10;
    monthToNum["December"] = 11;
    cin >> t; getchar();
    while (t--) {
        leerFecha();
        //cout << iniYear << " " << iniMonth << " " << iniDay << endl;
        cin >> k;

    }
    return 0;
}
