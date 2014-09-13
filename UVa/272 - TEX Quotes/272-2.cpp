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

string line;
string res;
int open = 1;

int
main() {
    while (getline(cin, line)) {
        res = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '\"') {
                if (open) res += "``";
                else res += "\'\'";   
                open = 1 - open;
            }
            else res += line[i];
        }
        cout << res << endl;
    }
	return 0;
}
