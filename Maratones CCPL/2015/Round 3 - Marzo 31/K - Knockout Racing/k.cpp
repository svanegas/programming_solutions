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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " = " << (x) << endl
#define pii pair<int, int>
#define MAXN 1005


int main(){
	int n, m;
	pii cars[MAXN];
	while(cin >> n >> m){
		for(int i = 0; i < n; ++i){
			int a, b;
			cin >> a >> b;
			cars[i] = pii(a,b);	
		}
		for(int x = 0; x < m; ++x){
			int a, b, t;
			cin >> a >> b >> t;
			int ans = 0;
			for(int i = 0; i < n; ++i){
				int ai = cars[i].first;
				int bi = cars[i].second;
				int n = abs(ai - bi);
				int pre = t / n;
				int pos;
				//D(t); D(n); D(ai); D(bi); D(pre); D(dec); D((int)pre);
				//printf("%d Modul %d = %d\n", (int) pre, 2, (int)pre % 2);
				if (pre % 2 == 0) {
					if(ai > bi) pos = abs(ai - (t % n));
					else pos = abs(ai + (t % n));
				}
				else {
					if(ai > bi) pos = abs(bi + (t % n));
					else pos = abs(bi - (t % n));
				}
				if(pos >= min(a,b) && pos <= max(a,b)) {
				 	ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;	
}
