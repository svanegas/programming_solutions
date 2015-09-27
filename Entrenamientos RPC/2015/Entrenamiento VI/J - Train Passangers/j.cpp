#include <iostream>
using namespace std;

typedef long long ll;

ll c, cur, leave, enter, stay;
int n;


int main() {
	cin >> c >> n;
	cur = 0;
	bool poss = true;
	for (int i = 0; i < n; ++i) {
		cin >> leave >> enter >> stay;
		if (i == 0 && leave > 0) poss = false;
		if (i == n - 1 && enter > 0) poss = false;
		cur += enter;
		cur -= leave;
		if (cur > c) poss = false;
		else if (cur < c && stay > 0) poss = false;
		if (i == n - 1 && cur > 0) poss = false;
		if (cur < 0) poss = false;
	}
	if (poss) cout << "possible" << endl;
	else cout << "impossible" << endl;
	return 0;
}