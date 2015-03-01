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

#define D(x) //cout << #x " = " << (x) << endl

using namespace std;



struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    double distancia(const point &o) const{
        double d1 = x-o.x, d2 = y-o.y;
        return sqrt(d1*d1 + d2*d2);
    }
};

const int MAXN = 18;
const double INF = 5000000.0;
vector <point> puntos;
bool emparejado[MAXN];
int n, z = 1;
double distTotal;

int
main() {
    while (cin >> n && n) {
        distTotal = 0.0;
        puntos.clear();
        for (int i = 0; i < 2*n; i++) {
            string nombre;
            double x, y;
            cin >> nombre >> x >> y;
            point p(x, y);
            puntos.push_back(p);
            emparejado[i] = false;
        }

        for (int i = 0; i < 2*n; i++) {
            if (!emparejado[i]) {
                double minDist = INF;
                int miPar = i;
                for (int j = i+1; j < 2*n; j++) {
                    if (emparejado[j]) continue;
                    double tmpDist = puntos[i].distancia(puntos[j]);
                    if (tmpDist < minDist) {
                        miPar = j;
                        minDist = tmpDist;
                    }
                }
                distTotal += minDist;
                printf("Entre %d y %d minDist: %.2f\n", i, miPar, minDist);
                emparejado[miPar] = true;
                emparejado[i] = true;
            }
        }
        printf("Case %d: %.2f\n", (z++), distTotal);
    }
    return 0;
}
