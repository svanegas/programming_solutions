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

vector <int> input;
vector <int> output;
int n;
int o;
bool maxPosible;

int
solve(int n) {
    if (n == 1) return 0;
    int res = 0;
    for (int i = 0; i < n/2; ++i)
        res += 2*(1+solve(n-i-1));
    return res;
}

vector <int>
sumar(vector <int> base, vector <int> agrego) {
    int j = agrego.size()-1;
    int tot = agrego.size();
    for (int i = base.size()-1; i >= base.size()-tot && !(i < 0); i--) {
        base[i] += agrego[j--];
    }
    return base;
}

bool
iguales(vector <int> cand) {
    if (cand.size() != output.size()) return false;
    for (int i = 0; i < output.size(); i++) {
        if (output[i] != cand[i]) return false;   
    }    
    return true;
}

bool
operar(int t, vector <int> vec) {
    if (maxPosible) return true;
    if (t == 1) return false;
    bool rpta = false;
    for (int i = t - 1; i >= vec.size()/2; i--) {
        vector <int> posible(vec);
        posible.resize(i);
            vector <int> agrego(vec);
            reverse(agrego.begin(), agrego.end());
            agrego.resize(vec.size()-i);
            vector <int> next = sumar(posible, agrego);
            if (iguales(next)) {
                maxPosible = true;
                rpta = true;
                break;
            }
        rpta = operar(i, next);
    }
    return rpta;
}

int
main() {
    while (cin >> n) {
        input.clear();
        output.clear();
        maxPosible = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            input.push_back(x);
        }
        cin >> o;
        for (int i = 0; i < o; i++) {
            int x; cin >> x;
            output.push_back(x);   
        }
        if (iguales(input)) {
            cout << 'S' << endl;
            continue;   
        }
        vector <int> rev(input);
        reverse(rev.begin(), rev.end());
        if (iguales(rev)) {
            cout << 'S' << endl;
            continue;
        }
        if (operar(n, input)) {
            cout << 'S' << endl;
            continue;
        }
        reverse(input.begin(), input.end());
        if (operar(n, input)) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}
