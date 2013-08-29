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

//class ImageDithering {
    //public:
        int count(string dithered, vector <string> screen) {
            int ans = 0;
            const int MAXN = 26;
            bool es[MAXN];
            memset(es, false, sizeof(es));
            for (int i = 0; i < dithered.size(); i++) {
                es[dithered[i]-'A'] = true;
            }
            for (int i = 0; i < MAXN; i++) {
                if (es[i]) cout << i << " si" << endl;
                else cout << i << " no" << endl;
            }
            for (int i = 0; i < screen.size(); i++) {
                for (int j = 0; j < screen[i].size(); j++) {
                    if (es[screen[i][j]-'A']) ans++;   
                }
            }
            return ans;
        }    
//};

int
main() {
    vector <string> screen;
    screen.push_back("AAAAAAAA");
    screen.push_back("ABWBWBWA");
    screen.push_back("AWBWBWBA");
    screen.push_back("ABWBWBWA");
    screen.push_back("AWBWBWBA");
    screen.push_back("AAAAAAAA");
    cout << count("BW", screen) << endl;
    return 0;   
}
