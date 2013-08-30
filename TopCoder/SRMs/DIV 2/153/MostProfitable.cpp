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

class MostProfitable {
    public:
        string bestItem(vector <int> costs, vector <int> prices,
                        vector <int> sales, vector <string> items) {
            string nombre = "";
            int mayor = 0;
            for (int i = 0; i < costs.size(); i++) {
                int ventas = prices[i]*sales[i];
                int ventas2 = costs[i]*sales[i];
                int tot = ventas - ventas2;
                if (tot && tot > mayor) {
                    mayor = tot;
                    nombre = items[i];   
                }
            }
            return nombre;                   
        }   
};

int
main() {
    
    return 0;
}
