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

int t;
long long bits, col;
string game, s, colS, bitsStr;
vector <int> possible;
int v[] = {1, 2, 3, 4, 6, 12};

long long
convert(string sFrom, char onKey) {
    long long res = 0;
    int exp = 0;
    for (int i = sFrom.size() - 1; i >= 0; i--) {
        if (sFrom[i] == onKey) res += ((int) pow(2.0, (double) exp));
        exp++; 
    }
    return res;
}

int
main() {
    cin >> t;
    while (t--) {
        cin >> game;
        possible.clear();
        for (int i = 0; i < 6; i++) {
            s = "111111111111";
            bitsStr = s.substr(0, v[i]);
            bits = convert(bitsStr, '1');
            for (int j = 0; j < 12; j += v[i]) {
                colS = game.substr(j, v[i]);
                col = convert(colS, 'X');
                bits &= col;
            }
            if (bits != 0) possible.push_back(v[i]);
        }
        cout << possible.size();
        for (int i = possible.size() - 1; i >= 0; i--) {
            printf(" %dx%d", 12/possible[i], possible[i]);
        }
        puts("");
    }
	return 0;
}
