#include <bits/stdc++.h>

using namespace std;

int main() {
  int bl, bh, ah;
  double EPS = 0.001;
  cin >> bl >> bh >> ah;
  int headX, headY, angle;
  cin >> headX >> headY >> angle;
  double angleRad = angle * acos(-1) / 180;
  double fX = headX + ah * cos(angleRad);
  double fY = headY + ah * sin(angleRad);
  if(fX > -EPS && fX < EPS + bh && fY > -EPS && fY < EPS + bl) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
