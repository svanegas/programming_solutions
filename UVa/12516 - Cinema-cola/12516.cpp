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

typedef pair <int, int> pareja;
typedef priority_queue <int, vector<int>, greater<int> > cola;
const int MAXR = 26;
const int MAXC = 100;
int r, c, p, z; // r <= 26,  2 <= c <= 99
int cine[MAXR+5][(100*2)+5]; //
map <int, cola> m;
set <int> reserv;

// k = 2n - 1

pareja convertir(string s) {
    pareja ret;
    int fila, col;
    fila = s[0] - 65; //'A' = 065
    col = atoi(s.substr(1).c_str());
    col = 2 * col - 1;
    ret = pareja(fila, col);
    return ret;
}

bool
sentar() {
    set <int> :: iterator it;
    for (it = reserv.begin(); it != reserv.end(); it++) {
        cola q = m[*it];
        while (!q.empty()) {
            int pos = q.top(); q.pop();
            if (cine[*it][pos-1] == 0) cine[*it][pos-1] = 1;
            else if (cine[*it][pos+1] == 0) cine[*it][pos+1] = 1;
            else return false;
        }
    }
    return true;
}

int
main() {
    while (scanf("%d%d", &r, &c) && (r && c)) {
        m.clear();
        reserv.clear();
        memset(cine, 0, sizeof(cine));
        scanf("%d", &p);
        while (p--) {
            string s, g;
            cin >> s >> g;
            pareja par = convertir(s);
            //cine[par.first][par.second] = 3;
            if (g == "-") cine[par.first][par.second - 1] = 1;
            else cine[par.first][par.second + 1] = 1;
        }
        scanf("%d", &z);
        while (z--) {
            string s; cin >> s;
            pareja par = convertir(s);
            reserv.insert(par.first);
            cola tmp = m[par.first];
            tmp.push(par.second);
            m[par.first] = tmp;
        }
        if (sentar()) puts("YES");
        else puts("NO");
    }
    return 0;
}
