//Santiago Vanegas Gil.
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
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int t;
const double PI = acos(-1.0);
double lat1, lat2, lon1, lon2;
double R = 6371009.0, C = 2 * PI * R;
double angle, arc, chord;

struct Vector3D {
  double x, y, z;
  Vector3D (double X, double Y, double Z) : x(X), y(Y), z(Z) {}  
  
  double dot(const Vector3D &b) {
    return x * b.x + y * b.y + z * b.z;
  }
};

double
toRad(double deg) {
  return deg * PI / 180;  
}

double
toDeg(double rad) {
  return rad * 180 / PI;
}

//http://en.wikipedia.org/wiki/N-vector
int
main() {
  cin >> t;
  while (t--) {
    cin >> lat1 >> lon1 >> lat2 >> lon2;
    lat1 = toRad(lat1); lon1 = toRad(lon1);
    lat2 = toRad(lat2); lon2 = toRad(lon2);
    Vector3D v1 = Vector3D(cos(lat1) * cos(lon1),
                           cos(lat1) * sin(lon1),
                           sin(lat1));
    Vector3D v2 = Vector3D(cos(lat2) * cos(lon2),
                           cos(lat2) * sin(lon2),
                           sin(lat2));
    double AdotB = v1.dot(v2);
    angle = acos(AdotB);
    arc = toDeg(angle) / 360.0 * C;
    chord = 2 * R * sin(angle / 2.0);
    printf("%.0f\n", abs(arc - chord));
  }  
  return 0;
}
