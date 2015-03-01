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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl;

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x) 
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x) 
{ stringstream s; s << x; int r; s >> r; return r; }

double
semi(double a, double b, double c) {
	return (a + b + c) * 0.5;	
}

double
area(double a, double b, double c) {
    double s = semi(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));	
}

double
rInCircle(double a, double b, double c) {
    double den = (0.5 * (a + b + c));
    return area(a, b, c) / (0.5 * (a + b + c));
}

double
rCircumCircle(double a, double b, double c) {
    return a * b * c / (4.0 * area(a, b, c));    
}

double
circA(double r) {
    return PI * r * r;    
}

double a, b, c;

int
main() {
	while (cin >> a >> b >> c) {
    	if (a == 0 || b == 0 || c == 0) {
    	   printf("%.4f %.4f %.4f\n", 0.0, 0.0, 0.0);
           return 0;   
    	}
    	double rIn = rInCircle(a, b, c);
    	double aIn = circA(rIn);
    	double aTria = area(a, b, c);
    	double rOut = rCircumCircle(a, b, c);
    	double aOut = circA(rOut);
    	printf("%.4f %.4f %.4f\n", (aOut - aTria) + EPS, (aTria - aIn) + EPS, aIn + EPS);
    }
	return 0;
}
