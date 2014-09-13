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

int t, n, heinze = 0;

int
trampa(vector <double> v1, vector <double> v2) {
    if (v1.size() == 1) return v1[0] > v2[0];
    int maxiI = -1, maxiJ = -1;
    for (int i = 0; i < v1.size(); i++) {
        maxiJ = -1;
        for (int j = i; j < v2.size(); j++) {
            vector <double> sig1 = v1, sig2 = v2;
            sig1.erase(sig1.begin() + i);
            sig2.erase(sig2.begin() + j);
            int suma = v1[i] > v2[j] ? 1 : 0;
            heinze++;
            maxiJ = max(maxiJ, suma + trampa(sig1, sig2));
        }
        maxiI = max(maxiI, maxiJ);
        break;
    }
    return maxiI;
}

int
normal(vector <double> v1, vector <double> v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    bool cogido[12];
    int tot = 0, cogidos = 0;
    memset(cogido, false, sizeof cogido);
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (!cogido[j]) {
                if (v2[j] > v1[i]) {
                    cogido[j] = true;
                    cogidos++;
                    break;   
                }
            } 
        }
    }
    return v1.size() - cogidos;    
}

int
main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> n;
        vector <double> v1, v2;
        for (int i = 0; i < n; i++) {
            double xi; cin >> xi;
            v1.push_back(xi);
        }   
        for (int i = 0; i < n; i++) {
            double xi; cin >> xi;
            v2.push_back(xi);
        }
        printf("Case #%d: %d %d\n", z, trampa(v1, v2), normal(v1, v2));
        //cout << trampa(v1, v2) << endl;
    }
	return 0;
}
