using namespace std;
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


#define D(x) cout << #x " = " << (x) << endl

typedef long long ll;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

template <class T> ll toll(const T &x)
{ stringstream s; s << x; ll r; s >> r; return r;}

ll n;
string line;

int main() {
	while (getline(cin, line)) {
		sscanf(line.c_str(), "%lld:", &n);
		set <ll> nums;
		
		int pos;
		for (pos = 0; pos < line.size(); ++pos) {
			if (line[pos] == ':') break;	
		}
		line = line.substr(pos + 1, line.size());
		stringstream ss(line);
		ll x;
		while (ss >> x) {
			nums.insert(x);
			//printf("Inserto %lld\n", x);
		}
		if (nums.size() == 0) {
			puts("Goku needs to find them all!");
		}
		else if (nums.size() == n) {
			puts("Goku already has them all!");
		}
		else {
			bool printed = false;
			for (ll i = 1LL; i <= n; ++i) {
				if (!nums.count(i)) {
					if (printed) printf(" ");
					printf("%lld", i);
					printed = true;
				}
			}
			puts("");
		}
	}
	return 0;
}
