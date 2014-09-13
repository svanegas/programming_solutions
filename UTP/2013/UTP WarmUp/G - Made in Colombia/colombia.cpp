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
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

int
main() {
    ull n;
    while (cin >> n && n) {
        ull tot = 0;
        ull med;
        priority_queue <ull> antes;
        priority_queue <ull, vector <ull>, greater<ull> > despues;
        for (ull i = 0; i < n; i++) {
            ull x; cin >> x;
            if (i == 0) med = x;
            if (x <= med) antes.push(x);
            else despues.push(x);
            
            if (antes.size() > despues.size() && antes.size() - despues.size() != 1) {
                despues.push(antes.top()); antes.pop();
            }
            if (despues.size() > antes.size()) {
                antes.push(despues.top()); despues.pop();
            }
            med = antes.top();
            tot += med;
        }
        double ans = double(tot) / double(n);
        ans = floor(ans*100+0.5)/100;
        printf("%.2f\n", ans);
    }
    return 0;
}
