#include <iostream>
#include <algorithm>
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
#include <bitset>

#define D(x) cout << "[DEBUG]: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 18;
int mat[MAXN][MAXN];

bool
solve(int sq) {
    //Filas
    int sum = 0;
    for (int j = 0; j < sq; j++) {
        sum += mat[0][j];
    }
    for (int i = 1; i < sq; i++) {
        int sum2 = 0;
        for (int j = 0; j < sq; j++) {
            sum2 += mat[i][j];
        }
        if (sum2 != sum) return false;
    }

    //Columnas
    sum = 0;
    for (int i = 0; i < sq; i++) {
        sum += mat[i][0];
    }
    for (int j = 1; j < sq; j++) {
        int sum2 = 0;
        for (int i = 0; i < sq; i++) {
            sum2 += mat[i][j];
        }
        if (sum2 != sum) return false;
    }

    //Diagonales
    sum = 0;
    int sum2 = 0;
    for (int i = 0; i < sq; i++) {
        sum += mat[i][i];
        sum2 += mat[sq - 1 - i][i];
    }
    return sum == sum2;
}

int
main() {
    string line;
    while (getline(cin, line)) {
        puts("Entro");
        stringstream ss(line);
        int x;
        int sum = 0;
        int index = 0;
        vector <int> arr;
        while (ss >> x) {
            sum += x;
            arr.push_back(x);
        }
        int sz = (int) sqrt(arr.size());
        bool could = false;
        if (sz * sz == arr.size()) {
            if (arr.size() == 16 && sum % 4 != 0) {
                cout << "N" << endl;
                continue;
            }
            else if (arr.size() == 9 && sum % 3 != 0) {
                cout << "N" << endl;
                continue;
            }
            else if (arr.size() == 4 && sum % 2 != 0) {
                cout << "N" << endl;
                continue;
            }
            do {
                int sq = (int) sqrt(arr.size());
                int ind = 0;
                for (int i = 0; i < sq; i++) {
                    for (int j = 0; j < sq; j++) {
                        mat[i][j] = arr[ind++];
                    }
                }
                if (solve(sq)) {
                    could = true;
                    puts("------\n--------\n-------");
                    for (int i = 0; i < sq; i++) {
                        for (int j = 0; j < sq; j++) {
                            cout << mat[i][j] << " ";
                        }
                        puts("");
                    }
                    break;

                }
            }
            while (next_permutation(arr.begin(), arr.end()));
        }
        if (could) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
