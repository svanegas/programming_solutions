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

class StreetParking {
    public:
        int freeParks(string street) {
            int cont = 0;
            for (int i = 0; i < street.size(); i++) {
                if (street[i] == 'D' || street[i] == 'B' || street[i] == 'S')
                    continue;
                if (i < street.size()-1 && (street[i+1] == 'B' || street[i+1] == 'S'))
                    continue;
                if (i < street.size()-2 && street[i+2] == 'B') continue;
                if (i > 0 && street[i-1] == 'S') continue;
                cont++;
            }
            return cont; 
        }    
};

int
main() {

    return 0;
}
