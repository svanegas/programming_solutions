#include <algorithm>
#include <iostream>
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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
priority_queue <ll> q;

int
main() {
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(x);
	}
	ll maxi = -1;
	ll dia = 1;
	while (!q.empty()) {
		maxi = max(maxi, (dia++) + q.top()); q.pop();
	}
	cout << maxi + 1 << endl;
    return 0;
}
