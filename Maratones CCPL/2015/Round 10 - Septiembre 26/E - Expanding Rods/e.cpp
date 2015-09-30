// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

double l, lp, n, c;
const double EPS = 1e-11;
const double PI = acos(-1.0);

inline double f(double x) {
  return sin(x) - ((l * x) / lp);
}

double
bisection(double xi, double xs, double tol) {
  double fxi = f(xi);
  double fxs = f(xs);
  double result;
  if (fxi == 0.0) return xi;
  else if (fxs == 0.0) return xs;
  else { //if (fxi * fxs < 0.0) {
    double xm = (xi + xs) / 2.0;
    double fxm = f(xm);
    double error = tol + 1.0;
    while (error > tol && fxm != 0.0) {
      if (fxi * fxm < 0.0) {
        xs = xm;
        fxs = fxm;
      }
      else {
        xi = xm;
        fxi = fxm;
      }
      double xaux = xm;
      xm = (xi + xs) / 2.0;
      fxm = f(xm);
      error = fabs(xm - xaux);
    }
    return xm;
  }
}

int
main() {
  while (scanf("%lf %lf %lf", &l, &n, &c) && l >= 0.0) {
    if (n == 0.0 || c == 0.0 || l == 0.0) puts("0.000");
    else {
      lp = (1.0 + n * c) * l;
      double alpha = bisection(EPS, PI, EPS);
      double r = lp / (2.0 * alpha);
      double ans = r - r * cos(alpha);
      printf("%.3f\n", ans);
    }
  }
  return 0;
}
