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

const int MAXN = 100000005;
int n, sum;
int p[MAXN];

int
buscar(int i) {
    if (i > sum) return -1;
    if (p[i] == 1) return i;
    return -1;
}

int
main() {
    while (cin >> n) {
        sum = 0;
        vector <int> pun;
        pun.push_back(sum);
        int x;
        int answer = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> x;
            sum += x;
            pun.push_back(sum);
        }
        cin >> x; sum += x;
        memset(p, 0, sizeof(int)*(sum+5));
        for (int i = 0; i < pun.size(); i++) p[pun[i]] = 1;
        double tot = double(sum)/3;
        int tot2 = sum/3;
        if (tot - floor(tot) != 0.0) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < pun.size(); i++) {
            int punto = pun[i];
            int cant = 0;
            cant++;
            for (int k = 0; k < 2; k++) {
                punto += tot2;
                int ans = buscar(punto);
                if (ans == -1) break;
                else cant++;
            }
            if (cant == 3) answer++;
        }
        cout << answer << endl;
    }
    return 0;
}
