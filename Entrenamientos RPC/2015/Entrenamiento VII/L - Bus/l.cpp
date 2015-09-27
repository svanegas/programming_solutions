#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map <int, ll> m;
int t;

int main() {
	double prev = 0.0;
	for (int i = 1; i <= 30; ++i) {
		double next = prev + 0.5;
		next *= 2.0;
		prev = next;
		m[i] = (ll) prev;
	}
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << m[n] << endl;	
	}
	return 0;	
}

