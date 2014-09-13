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

#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const int MAXN = 1005;
int n, p;
vector <int> conj[MAXN];
map <int, int> enCual;

int
main() {
    while (cin >> n >> p && n && p) {
        int pag = 0;
        enCual.clear();
        for (int i = 0; i <= n; i++) conj[i].clear();
        for (int i = 1; i <= n/2; i++) {
            if (i % 2 == 1) pag++;
            conj[pag].push_back(i);
            enCual[i] = pag;
        }
        pag++;
        for (int i = (n/2)+1; i <= n; i++) {
            if (i % 2 == 1) pag--;
            conj[pag].push_back(i); 
            enCual[i] = pag;
        }
        int quitar = enCual[p];
        for (int i = 0; i < conj[quitar].size(); i++) {
            if (conj[quitar][i] != p) {
                cout << conj[quitar][i];
                if (i != conj[quitar].size() - 1) cout << " ";
            }
            
        }
        puts("");
    }
    return 0;
}
