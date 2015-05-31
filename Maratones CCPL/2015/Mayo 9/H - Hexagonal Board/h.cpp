//Santiago Vanegas Gil.
#include <bits/stdc++.h>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

void
printfHead(int n) {
	for (int k = 1; k <= n; ++k) {
		int spaces = 2 * (n - k) + 1;
		int slashes = k - 1;
		for (int i = 0; i < spaces; ++i) printf(" ");
		while (slashes-- > 0) {
			printf("_/ \\");
    }
    puts("_");
  }
}

void
printConstant(int n) {
	for (int k = 1; k <= n * 2; ++k) {
		int slashes = n;
		if (k % 2 == 0) {
			while (slashes--) {
				printf("\\_/");
				if (slashes) printf(" ");
      }
		}
    else {
			while (slashes--) {
				printf("/ \\");
				if (slashes) printf("_");
      }
    }
    puts("");
  }
}

void
printBottom(int n) {
	for (int k = 1; k < n; ++k) {
		int spaces = 2 * k;
		int slashes = n - k;
    for (int i = 0; i < spaces; ++i) printf(" ");
		while (slashes-- > 0) {
			printf("\\_/");
			if (slashes) printf(" ");
    }
    puts("");
  }
}

void
printHexagonal(int n) {
	printfHead(n);
	printConstant(n);
	printBottom(n);
	puts("***");
}

int main() {
  int n;
  while (cin >> n && n != -1) {
    printHexagonal(n);	
  }
  return 0;
}
