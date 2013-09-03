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

class DiskSpace {
    public:
        int minDrives(vector <int> used, vector <int> total) {
            int usado = 0;
            for (int i = 0; i < used.size(); i++) usado += used[i];
            int tot = 0;
            int cont = 0;
            priority_queue <int> q;
            for (int i = 0; i < total.size(); i++) q.push(total[i]);
            while (!q.empty()) {
                tot += q.top(); q.pop();
                cont++;
                if (usado <= tot) break;   
            }
            return cont;
        }    
};

int
main() {

    return 0;
}
