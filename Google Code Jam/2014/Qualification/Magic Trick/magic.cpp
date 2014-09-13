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

const int n = 4;
const int m = 4;
int t, firstQ, secondQ;
int cards[n][m], mixed[n][m];
map <int, bool> cand;
vector <int> chosen;

int
main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cand.clear();
        chosen.clear();
        cin >> firstQ; firstQ--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> cards[i][j];   
                if (i == firstQ) cand[cards[i][j]] = true;
            }
        }
        cin >> secondQ; secondQ--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mixed[i][j];
                if (i == secondQ && cand[mixed[i][j]])
                    chosen.push_back(mixed[i][j]);
            }   
        }
        if (chosen.size() == 0) printf("Case #%d: Volunteer cheated!\n", z);
        else if (chosen.size() == 1) printf("Case #%d: %d\n", z, chosen[0]);
        else printf("Case #%d: Bad magician!\n", z);
    }
	return 0;
}
