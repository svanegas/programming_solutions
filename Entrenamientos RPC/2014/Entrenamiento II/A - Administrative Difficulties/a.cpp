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

typedef long long ll;

int t, n, m;
map <string, ll> price;
map <string, ll> pick;
map <string, ll> cost;

map <string, string> uses;
map <string, ll> bill;

set <string> spies;

int
main() {
    cin >> t;
    while (t--) {
        price.clear();
        pick.clear();
        cost.clear();
        uses.clear();
        bill.clear();
        spies.clear();
        cin >> n >> m;
        while (n--) {
            string nomb;
            ll p, pu, cst;
            cin >> nomb >> p >> pu >> cst;
            price[nomb] = p;
            pick[nomb] = pu;
            cost[nomb] = cst;
        }
        while (m--) {
            ll tiempo, dist, perc;
            string nameSpy, descCar;   
            char type;
            cin >> tiempo >> nameSpy >> type;
            spies.insert(nameSpy);
            switch (type) {
                case 'p':
                    cin >> descCar;
                    if (bill[nameSpy] != -1) {
                        if (uses[nameSpy] == "") {
                            ll aSumar = pick[descCar];
                            bill[nameSpy] += aSumar; 
                            uses[nameSpy] = descCar;  
                        }
                        else {
                            bill[nameSpy] = -1;   
                        }
                    }
                    break;
                case 'r':
                    cin >> dist;
                    if (bill[nameSpy] != -1) {
                        if (uses[nameSpy] != "") {
                            string usando = uses[nameSpy];
                            ll aRecorr = cost[usando] * dist;
                            bill[nameSpy] += aRecorr;
                            uses[nameSpy] = "";
                        }
                        else {
                            bill[nameSpy] = -1; 
                        }   
                    }
                    break;
                case 'a':
                    cin >> perc;
                    if (bill[nameSpy] != -1) {
                        if (uses[nameSpy] != "") {
                            string chocado = uses[nameSpy];
                            //double pChoque = double(price[chocado]) * (double(perc) / 100);
                            //ll pChoqueInt = (ll) ceil(pChoque);
                            ll pChoqueInt = (perc * price[chocado] + 99) / 100;
                            bill[nameSpy] += pChoqueInt;
                        }
                        else {
                            bill[nameSpy] = -1;   
                        }
                    }
                    break;       
            }
        }
        set <string> :: iterator it;
        for (it = spies.begin(); it != spies.end(); it++) {
            string actual = *it;
            //cout << actual << " tiene " << bill[actual] << endl;
            if (uses[actual] != "") bill[actual] = -1;
            cout << actual << " ";
            if (bill[actual] == -1) cout << "INCONSISTENT" << endl;
            else cout << bill[actual] << endl;
        }
    }
	return 0;
}
