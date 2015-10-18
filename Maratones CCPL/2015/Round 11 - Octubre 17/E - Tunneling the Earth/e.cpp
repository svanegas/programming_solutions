#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);
double lat1, lat2, lon1, lon2;
double R = 6371009.0, C = 2 * PI * R;
double angle, arc;

struct Vector3D {
  double x, y, z;
  Vector3D (double X, double Y, double Z) : x(X), y(Y), z(Z) {}

  double dot(const Vector3D &b) {
    return x * b.x + y * b.y + z * b.z;
  }
};

double toRad(double deg) {
  return deg * PI / 180.0;
}

double toDeg(double rad) {
  return rad * 180.0 / PI;
}

double
distance(double lat1, double lon1, double lat2, double lon2) {
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
  double chord = 2 * R * sin(angle/2.0);
  return abs(arc - chord);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    double lat1, lon1, lat2, lon2;
    cin >> lat1 >> lon1 >> lat2 >> lon2;
    printf("%.0f\n", distance(lat1, lon1, lat2, lon2));
  }
  return 0;
}
