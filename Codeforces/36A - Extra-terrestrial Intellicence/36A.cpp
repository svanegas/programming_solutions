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


int
main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    getline(cin, line);
    getline(cin, line);
    int dist = 0;
    int distOtros;
    bool encontre = false;
    for (int i = 0; i < line.size(); i++) {
        if (encontre && line[i] == '1') {
            dist = i - dist;
            break;
        }
        if (!encontre && line[i] == '1') {
            dist = i;
            encontre = true;
        }
    }
    encontre = false;
    for (int i = 0; i < line.size(); i++) {
        if (encontre && line[i] == '1') {
            distOtros = i - distOtros;
            if (distOtros != dist) {
                cout << "NO" << endl;
                return 0;   
            }
            distOtros = i;
        }
        if (!encontre && line[i] == '1') {
            distOtros = i;
            encontre = true;
        }
    }
    cout << "YES" << endl;
	return 0;
}
