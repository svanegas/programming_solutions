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

class ProfitCalculator {
	public:
        int percent(vector <string> items) {
            double pag, prec;
            pag = prec = 0.0;
            for (int i = 0; i < items.size(); i++) {
                stringstream ss(items[i]);
                string t1, t2;
                ss >> t1;
                ss >> t2;
                cout << "t1: " << t1 << endl;
                cout << "t2: " << t2 << endl;
                printf("Pag es: %f y prec es: %f", pag, prec); 
                pag += atof(t1.c_str());
                prec += atof(t2.c_str());
                printf(" Les sumo %f y %f, quedan en %f y %f\n", atof(t1.c_str()),
                        atof(t2.c_str()), pag, prec);
            }
            double tot = pag - prec;
            printf("Tot es %f\n", tot);
            int ret = int((tot/pag)*100);
            printf("Por lo cual retorno %d\n", ret);
            return ret;
        }    
};

int
main() {

    return 0;
}
