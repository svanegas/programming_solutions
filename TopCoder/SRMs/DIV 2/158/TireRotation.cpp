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

class TireRotation {
    public:
        int getCycle(string initial, string current) {
            if (initial == current) return 1;
            string tmp = "";
            stringstream ss;
            ss << initial[3];
            ss << initial[2];
            ss << initial[0];
            ss << initial[1];
            ss >> tmp;
            if (tmp == current) return 2;
            ss.clear();
            ss << initial[1];
            ss << initial[0];
            ss << initial[3];
            ss << initial[2];
            ss >> tmp;
            if (tmp == current) return 3;
            ss.clear();
            ss << initial[2];
            ss << initial[3];
            ss << initial[1];
            ss << initial[0];
            ss >> tmp;
            if (tmp == current) return 4;
            return -1;
        }
};

int
main() {

    return 0;
}
