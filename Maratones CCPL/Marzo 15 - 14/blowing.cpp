using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
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

//157.253.238.31/boca/ team501

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) //cout << #x " = " << (x) << endl;

const int MAXN = 20;
int n;
long long m,c;
int consumo[MAXN];
bool estado[MAXN];

int
main() {
    int z = 1;
    while (cin >> n >> m >> c && (n || m || c)){
        bool blown = 0;
        for(int i=0; i<n; ++i){
            estado[i] = false;
            cin >> consumo[i];
        }
        long long maxi = 0;
        long long actual = 0;

        while(m--) {
            int num;
            cin >> num;
            D(num);
            D(m);
            if(!estado[num-1]) {
                estado[num-1] = true;
                actual += consumo[num-1];
                if(actual > c){
                    blown = 1;
                }
                D(maxi);
                D(actual);
                //if(actual > maxi) maxi = actual;
                maxi = max(maxi, actual);
            }
            else {
                estado[num-1] = false;
                actual -= consumo[num-1];
            }
            //if (m == 0) break;
        }
        cout << "Sequence " << z++ << endl;

        if(blown) cout << "Fuse was blown." << endl;
        else cout << "Fuse was not blown." << endl << "Maximal power consumption was " << maxi << " amperes." << endl;
        cout << endl;
    }
    return 0;
}
