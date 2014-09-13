#include <algorithm>
#include <iostream>
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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

const int MAXRING = 25;
typedef vector <int> anill;
int c, n, r;
vector <anill> original;
vector <anill> contrario;
bool usado[MAXRING];

bool
esta(vector <int> aguja) {
    for (int i = 0; i < n; i++) {
        if (aguja == contrario[i]) return true;
    }
    return false;
}

int
main() {
    cin >> c;
    while (c--) {
        original.clear();
        contrario.clear();
        bool nulo = false;
        bool invalid = false;
        bool repeat = false;
        cin >> r >> n;
        for (int i = 0; i < n; i++) {
            vector <int> rune;
            vector <int> inver;
            memset(usado, false, sizeof(usado));
            for (int j = 0; j < 3; j++) {
                int x; cin >> x;
                if (x == 0) nulo = true;
                if (abs(x) > r) invalid = true;
                if (usado[abs(x)]) repeat = true;
                rune.push_back(x);
                inver.push_back(x*-1);
                usado[abs(x)] = true;
            }
            int trash; cin >> trash;
            original.push_back(rune);
            contrario.push_back(inver);
        }
        if (nulo) {
            puts("INVALID: NULL RING");
            continue;
        }
        if (invalid) {
            puts("INVALID: RING MISSING");
            continue;
        }
        if (repeat) {
            puts("INVALID: RUNE CONTAINS A REPEATED RING");
            continue;
        }
        for (int i = 0; i < n; i++) {
            sort(original[i].begin(), original[i].end());
            sort(contrario[i].begin(), contrario[i].end());
        }
        bool sePuede = false;
        for (int i = 0; i < n; i++) {
            if (!esta(original[i])) {
                sePuede = true;
                break;
            }
        }
        if (sePuede) puts("RUNES SATISFIED!");
        else puts("RUNES UNSATISFIABLE! TRY ANOTHER GATE!");
    }
    return 0;
}
